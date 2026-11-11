#include<bits/stdc++.h>
using namespace std; 
int n,m,cnt[300005],a[500005],nw[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	if(n*n*n<=1e8){
		for(int i=1;i<=n;i++){//±©Á¦´úÂëO(n^3) 24·Ö 
			memset(cnt,0,sizeof(cnt));
			memset(nw,0,sizeof(nw));
			int num=0;
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]==0){
					cnt[a[j]]++;
					nw[++num]=a[j];
				}else{
					cnt[a[j]]=1;
					int id;
					for(int k=1;k<=num;k++){
						if(nw[k]==a[j]){
							id=k;
							break;
						}
					}
					for(int k=id+1;k<=num;k++){
						cnt[nw[k]]=0;
						nw[k]=0;
					}
					num=id;
				}
			} 
			for(int j=1;j<=num;j++){
				ans[nw[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
