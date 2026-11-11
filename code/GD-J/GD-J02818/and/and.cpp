#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,TLL=(1<<32)-1;
int a[500009],ans=0,f[2009][2009],ma=0;
int main(){
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(a[i],ma);
		}
		cout<<ma;	
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;	
	}else if(m==n){
		ma=a[1];
		for(ll i=2;i<=n;i++){
			ma&=a[i];
		}
		cout<<ma;
	}else{
		for(ll i=1;i<=n;i++){
			f[i][1]=a[i];
			f[i][0]=TLL;
		}
		for(ll i=2;i<=n;i++){
			for(ll j=1;j<=m;j++){
				for(ll k=2;k<=i;k++){
					f[i][j]=max(f[i][j],max(f[i-1][j],f[k-1][j-1]&a[k]));
				}
			}
		}
		for(ll i=1;i<=n;i++){
			ans=max(ans,f[i][m]);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
