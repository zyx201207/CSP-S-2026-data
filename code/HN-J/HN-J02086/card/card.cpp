#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
int n,m,a[100005],ans[100005],b[100005],c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=i;
		memset(b,0,sizeof b); 
		memset(c,0,sizeof c); 
		for(int j=i;j<=n;j++,k++){
			if(b[a[j]]){
				k=min(b[a[j]],k);
			}else{
				c[++k]=a[j];
				b[a[j]]=k;
			}
		}
		for(int j=i;j<=k;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
