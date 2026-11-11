#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010]={0},le=0,d[500010]={0},ans[300010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				le++;
				d[le]=a[j];
				b[a[j]]=1;
			}else{
				for(int k=1;k<=le;k++){
					if(d[k]==a[j]){
						for(int m=k+1;m<=le;m++){
							b[d[m]]=0;
						}
						le=k;
						d[le]=a[j];
						break;
					}
				}
				
			}
		}
		for(int j=1;j<=le;j++){

			ans[d[j]]+=1;
		}

		memset(b,0,sizeof(b));
		memset(b,0,sizeof(b));
		le=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
