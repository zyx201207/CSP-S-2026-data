#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],f[N],r,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]){
			if(f[a[i]]>r){
				f[a[i]]=(++r);
			}else{
				for(int ii=f[a[i]]+1;ii<=r;ii++){
					f[a[f[ii]]]=0;
				}
				r=f[a[i]];
			}
		}else{
			f[a[i]]=(++r);
		}
	}
	for(int i=1;i<=m;i++){
		if(f[i]&&f[i]<=r){
			ans[i]++;
		}
	}
	int i=2;
	while(i<=n){
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[i]]){
					for(int ii=f[a[i]]+1;ii<=r;ii++){
						f[a[f[ii]]]=0;
					}
					r=f[a[i]];
			}else{
				f[a[i]]=(++r);
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i]){
				ans[i]++;
			}
		}
		i++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
