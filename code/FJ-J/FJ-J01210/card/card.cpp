#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],d[500005],e,f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		e=0;
		for(int j=i;j<=n;j++){
			
				if(b[a[j]]==0){
					b[a[j]]=1;
					d[++e]=j;
					f[a[j]]++;
				}else{
					for(int q=e;q>=1;q--){
						if(a[d[q]]==a[j]){
							e=q;
							break;
						}else{
							b[a[d[q]]]=0;
							f[a[d[q]]]--;
						}
					}
					d[e]=j;
				}
			}
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	cout<<endl;
}