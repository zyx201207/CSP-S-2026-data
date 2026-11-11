#include<bits/stdc++.h>
#define int long long 
using namespace std;
int v[10005];
int s[1000005][3];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	int mx=INT_MIN; 
	int x=0;
	for(int len=1;len<=n;len++){
		int cnt=0;
		for(int i=1;i<=len;i++){
			if(v[i]>mx){
				mx=max(mx,v[i]);
			}
		}
		for(int i=1;i<=len;i++){
			cnt+=mx-v[i];
		}
		s[++x][1]=cnt;
		s[++x][2]=len;
	} 
	int ans=0;
	for(int i=1;i<=x;i++){
		if(s[i][1]<=m){
			ans=max(ans,s[i+1][2]);
		}
	}
	cout<<ans;
	return 0;
}
