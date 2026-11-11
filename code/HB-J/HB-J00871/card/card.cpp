#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int cnt[500005];
bool f[300005];
int c;
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				for(int k=1;k<=c;k++){
					if(b[k]==a[j]){
						for(int l=k+1;l<=c;l++){
							f[b[l]]=0;
						}
						c=k;
						break;
					}
				}
			}else{
				b[++c]=a[j];
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(f[j]){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}  
