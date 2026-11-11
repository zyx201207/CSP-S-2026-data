#include <bits/stdc++.h>
using namespace std;
int n,a,x,y;
char b;
long long len=0,ans=0,c=0;
vector<pair<int,char>> m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		m.push_back({a,b});
		len+=a;
	}
	int l=0,r=n-1;
	while(l<r){
		if(m[l].first>=m[r].first){
			m[l].first-=m[r].first;
			if(m[l].second!=m[r].second){
				ans+=m[r].first;
			}
			r--;
		}
		else{
			m[r].first-=m[l].first;
			if(m[l].second!=m[r].second){
				ans+=m[l].first;
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
