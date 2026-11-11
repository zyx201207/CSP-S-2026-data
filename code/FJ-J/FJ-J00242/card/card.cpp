#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],lin[500005],lin2[500005],b[500005];
void yu(){
	for(int i=1;i<=n;i++){
		int lon=0;
		memset(lin,0,sizeof(lin));
		memset(lin2,0,sizeof(lin2));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(lin[a[j]]==1){
				for(int iii=lin2[a[j]];iii<=lon;iii++){
					lin[b[iii]]=0;
					if(b[iii]!=a[j]) lin2[b[iii]]=0;
					b[iii]=0;
				}
				lin[a[j]]=1;
				lon=lin2[a[j]];
			}
			else{
				lon++;
				b[lon]=a[j];
				lin[a[j]]=1;
				lin2[a[j]]=lon;
			}
		}
		for(int j=1;j<=m;j++) if(lin[j]==1) ans[j]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	yu();
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
