#include<bits/stdc++.h>
using namespace std;
int a[500005];
//每一局 
int b[500005];
// 是否在桌上  
bool vis[500005];
bool jin[500005];
int liu[500005];
bool isa=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]<a[i-1])isa=0;
	}
	if (isa){
		for (int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		int nowr=0;//最右边 
		for (int j=i;j<=n;j++){
			if (!vis[a[j]]){
				vis[a[j]]=1;
				b[++nowr]=a[j];
			}
			else{
				for (int z=1;z<=nowr;z++){
					if (b[z]==a[j]){
						for (int k=z+1;k<=nowr;k++){
							vis[b[k]]=0;
							b[k]=0;
						}
						nowr=z;
						break;
					}
				}
			}
		}
		for (int j=1;j<=nowr;j++){
			liu[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<liu[i]<<" ";
	}
}

