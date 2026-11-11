#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[300005],ans[300005],ccf[200005],t;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=n;j++){
		for(int k=j;k<=n;k++){
			if(b[a[k]]==1){
				while(ccf[t]!=a[k]){
					b[ccf[t]]=0;
					ccf[t]=0;t--;
				}
				continue;
			}
			t++;
			ccf[t]=a[k];
			b[a[k]]=1;
		}
		while(ccf[1]){
			ans[ccf[t]]++;
			b[ccf[t]]=0;
			ccf[t]=0;t--;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0; 
}
