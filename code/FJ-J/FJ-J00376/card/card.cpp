#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5,M=3*1e5+5;
int a[N],b[M],c[M];
bool cmp(int a,int b){
	return a>b;
}
struct node{
	int id,n;
}vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;cin>>n>>m;
	int g1=0,g2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) g1++;
		if(a[i]>=a[i-1]) g2++;
	}
	long long cnt=0;
	if(g2==n&&g1!=n){
		for(int i=1;i<=m;i++){
			cout<<1;
		}
		return 0;
	}else if(g1==n){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
	if(g1>0){
		for(int i=1;i<=n;i++){
			cnt=0;
			memset(b,0,sizeof(b));
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;j++){
				cnt++;
				if(vis[a[j]].n==1){
					b[cnt]=a[j];
					for(int k=vis[a[j]].id;k<=cnt;k++){
						b[k]=0;
						vis[k].n=0;
					}
					cnt++;
					vis[a[j]].n=1;
					vis[a[j]].id=j;
				}else{
					b[cnt]=a[j];
				}
				vis[a[j]].n=1;
				vis[a[j]].id=j;
			}
			for(int i=1;i<=cnt;i++){
				//if(b[i]==0) continue;
				c[b[i]]++;
				//cout<<b[i]<<' ';
			}
			//cout<<'\n';
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
	}
	
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
