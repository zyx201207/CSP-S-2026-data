#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	vector<pair<int,char>> s;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		l+=a;
		s.push_back({a,c});
	}
	unsigned long long ans=0;
	for(int i=0,j=s.size()-1,x=0,y=l-1;i<j;){
		if(i!=j){
			int m = min(s[i].first,s[j].first);
			x+=m;
			y-=m;
			if(s[i].second!=s[j].second)
				ans+=m;
			if(s[i].first<s[j].first){
				s[i].first-=m;
				s[j].first-=m;
				i++;
			}
			else if(s[i].first>s[j].first){
				s[i].first-=m;
				s[j].first-=m;
				j--;
			}
			else {
				s[i].first-=m;
				s[j].first-=m;
				i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
