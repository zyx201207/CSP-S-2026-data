#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int cnt,la;
int id;
int belong[500005];
int si[500005];
int v[500005];
int f[500005];
int dsi[500005];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]||i==1){
			id++;
		}belong[i]=id;
		si[id]++;
		v[id]=a[i];
		//cout<<belong[i]<<" "<<si[i]<<" "<<v[i]<<endl;
	}
	for(int i=1;i<=id;i++){
		f[i]=f[i-1]+si[i]*v[i];
		dsi[i]=dsi[i-1]+si[i];
		//cout<<f[i]<<" "<<dsi[i]<<endl;
	}
	int t;
	for(int i=1;i<=id;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(v[i]*(dsi[i-1]-dsi[mid-1])-(f[i-1]-f[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		if(l==1)ans=max(ans,dsi[i]);
		else{
			ans=max(ans,
			dsi[i]-dsi[l-1]+(m-(v[i]*(dsi[i-1]-dsi[l-1])-(f[i-1]-f[l-1])))/(v[i]-v[l-1]));
		}//cout<<i<<" "<<l<<" "<<ans<<endl;
	}cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/


