#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int s[MAXN];
int pre[MAXN];
int ans=0;
signed  main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i],pre[i]=(i-1)*(a[i]-a[i-1])+pre[i-1];
	
	int l=1,r=1;
	for(;r<=n;r++){
//		int cha=(r-l)>>1ll;
		while(pre[r]-((l-1)*a[r]-s[l-1])>m&&l<r){
			l++;
//			cha=(r-l)>>1ll;
		}
//		cout<<pre[r]-((l-1)*a[r]-s[l-1])<<' '<<r<<' '<<l<<'\n';
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	return 0;
}

