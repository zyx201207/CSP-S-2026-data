#include<bits/stdc++.h>
using namespace std;
const int MAXN=8005;
int a[MAXN],b[MAXN];
int vis[MAXN];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		//vis1[i]=-1;
	}
	for(int i=1;i<=n;++i){
		int vis1[MAXN];
		fill(vis1+1,vis1+1+m+5,-1);
		vis[a[i]]++;
		vis1[a[i]]=1;
		for(int j=i+1;j<=n;++j){
			if(a[j]==i&&vis1[a[j]]==-1){
				
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout<<vis[i]<<" ";
	}
	//cout<<rand()%n+1<<endl;
	/*for(int i=1;i<=n;++i){
		for(int j=i,k=1;j<=n;++j){
			if(i==j){
				b[k]=a[j];
			}
			else{
				if(vis[a[j]]==0)
			}
		}
	}*/
	return 0;
}

