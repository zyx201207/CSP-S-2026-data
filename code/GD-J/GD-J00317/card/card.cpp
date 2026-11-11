#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],d[N],cut,len;
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(vis[a[i]]==false){
				d[++cut]=a[i];
				vis[a[i]]=true;
			}
			else{
				for(int j=1;j<=cut;j++){
					if(d[j]==a[i]){
						for(int x=j+1;x<=cut;x++){
							vis[d[x]]=false;
							d[x]=0;
						}
						cut=j;
						break;
					}
				}
			}
		}
		for(int i=1;i<=cut;i++){
			cout<<d[i]<<' ';
			ans[d[i]]++;
			d[i]=0;
		}
		cout<<endl;
		cut=0;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
