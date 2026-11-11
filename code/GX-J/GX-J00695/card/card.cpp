#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int vis[300005],xb[300005];
int tble[500005],p=0;
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int A=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]<=a[i])A++;
	}
	if(A==n){
		int cnt=0;
		for(int i=n;i>=1;i--){
			if(a[i]!=a[i+1]){
				ans[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;j++){
				if(vis[a[j]]==0){
					tble[++p]=a[j];
					vis[a[j]]=1;
				}
				else{
					bool f=0;
					int p1;
					for(int k=1;k<=p;k++){
						if(f==1){
							vis[tble[k]]=0;
							tble[k]=0;
						}
						else if(tble[k]==a[j]){
							p1=k;
							f=1;
						}
					}
					p=p1;
				}
			}
			for(int j=1;j<=p;j++){
				ans[tble[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
