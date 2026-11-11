#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[501000],f[301000],p[501000];
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=0;
		memset(p,0,sizeof(p));
		for(int j=i+1;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=l;k++)
				if(p[k]==a[j]){
					flag=false;
					l=k;
					break;
				}
			if(flag)p[++l]=a[j];
		}
		for(int j=1;j<=l;j++)
			f[p[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<f[i]<<' ';
	cout<<"\n";
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
