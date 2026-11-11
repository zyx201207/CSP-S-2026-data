#include<bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
long long ans=0;
vector<pair<int,char>> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s.push_back(make_pair(a,c));
	}
	int l=0,r=(int)s.size();
	r-=1;
	while(l<r){
		if(s[l].second!=s[r].second){
			if(s[l].first>s[r].first){
				ans+=s[r].first;
				s[l].first-=s[r].first;
				r--;
			}else if(s[l].first==s[r].first){
				ans+=s[l].first;
				r--;
				l++;
			}else{
				ans+=s[l].first;
				s[r].first-=s[l].first;
				l++;
			}
		}else{
			if(s[l].first>s[r].first){
				s[l].first-=s[r].first;
				r--;
			}else if(s[l].first==s[r].first){
				r--;
				l++;
			}else{
				s[r].first-=s[l].first;
				l++;
			}	
		}
	}cout<<ans;
	return 0;
}
