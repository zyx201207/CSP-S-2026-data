#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=5e3+4;
int n,m;
int ans[N];
int a[N],b[N];
int vis[N],t[N];
int buff[M][M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	} 
	if(m==1){
		cout<<n;
		return 0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				buff[i][j]=buff[i-1][j];
				if(a[i]==j) buff[i][j]+=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(buff[n][j]-buff[i-1][j]>=1) ans[j]++;
			}
		}
		for(int k=1;k<=m;k++) cout<<ans[k]<<' ';
		return 0;
	}
 	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++) b[j]=0,vis[j]=0,t[j]=0;
		for(int j=i;j<=n;j++){
			++cnt;
			if(vis[a[j]]){
				int ft=cnt;
				for(int k=t[a[j]]+1;k<=ft;k++) vis[b[k]]=0,cnt--;
			}else b[cnt]=a[j],vis[a[j]]=1,t[a[j]]=cnt;
		}
		for(int k=1;k<=m;k++) if(vis[k]) ans[k]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	
	
	return 0;
}

