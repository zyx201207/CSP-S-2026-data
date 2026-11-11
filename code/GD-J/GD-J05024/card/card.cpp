#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,a[N],b[N],d[N];
bool c[N],allA=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) allA=0;
	}
	if(allA){
		for(int i=1;i<=n;i++) d[a[i]]=max(d[a[i]],i);
		for(int i=1;i<=m;i++) cout<<d[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		//第i轮游戏
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++) b[j-i+1]=a[j];
		int nn=n-i+1;
		for(int j=1;j<=nn;j++){
			//处理到第j张牌
			int g=-1;
			for(int k=1;k<j;k++) if(b[j]==b[k]) g=k;
			if(g==-1) continue;
			for(int k=g;k<j;k++) b[k]=-1; 
		}
		for(int j=1;j<=nn;j++){
			if(b[j]==-1) continue;
			c[b[j]]=1;
		}
		for(int j=1;j<=m;j++) if(c[j]) d[j]++;
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}
