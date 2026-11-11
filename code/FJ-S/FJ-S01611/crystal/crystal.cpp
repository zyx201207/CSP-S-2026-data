#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	long long v[500010],s[500010],m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		s[i]=s[i-1]+(v[i]-v[i-1])*(i-1);
	}
	sort(v+1,v+n+1);
	int l=1,r=1;
	long long need=0;
	int ans=1;
	while(r+1<=n){
		need+=(r-l+1)*(v[r+1]-v[r]);
		if(need<=m)
			r++;
		else{
			while(need>m){
				need-=(v[r+1]-v[l]);
				l++; 
			}
			r++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans; 
	return 0;
} 
