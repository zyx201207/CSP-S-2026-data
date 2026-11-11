#include<bits/stdc++.h>
using namespace std;
const int M=5000005;
long long n,m,i,j,k,a[M],f[M],ans[M]={0},o;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			f[1]=a[1];
			bool t=0;
			for(k=1;k<=i;k++){
				if(a[k]==a[i]&&k!=i){
					t=1;
					o=k;
				}
				else f[i]=a[i];
			}
			if(t==1){
				for(k=i;k<=o;k++){
					a[k]=0;
				}
			}
			for(k=1;k<=n;k++)
			if(a[k]!=0)ans[k]++;
		}
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
