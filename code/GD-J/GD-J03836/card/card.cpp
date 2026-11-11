#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
int ic[5005],ci[5005],ans[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ic[j]=0;
			ci[j]=0;
		}
		int len=0;
		for(int j=i;j<=n;j++){
			bool q=(ic[a[j]]!=0);
			if(q){
				int p=ic[a[j]];
				for(int k=p;k<=len;k++){
					ic[ci[k]]=0;
					ci[k]=0;
				}
				len=p-1;
			}
			len++;
			ic[a[j]]=len;
			ci[len]=a[j];
		}
		for(int j=1;j<=m;j++){
			ans[j]+=(ic[j]!=0);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
