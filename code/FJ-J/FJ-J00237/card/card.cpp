#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],hp[500005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(hp,0,sizeof hp);
		memset(k,0,sizeof k);
		int len=0;
		for(int j=i;j<=n;j++){
			if(!k[a[j]]){
				hp[++len]=a[j];
				k[a[j]]++;
			}else{
				for(int l=1;l<=len;l++){
					if(hp[l]==a[j]){
						for(int ll=l;ll<=len;ll++){
							k[hp[ll]]--;
							hp[ll]=0;
						}
						len-=(len-l+1);
						hp[++len]=a[j],k[a[j]]++;
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)if(k[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
