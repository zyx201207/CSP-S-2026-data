#include<bits/stdc++.h>
using namespace std;
long long n,m,v,u=1;
bool a[200005][35],g[35];
void b(long long x,long long y){
	memset(g,0,sizeof(g));
	int cnt=0;
	while(x!=0){
		g[++cnt]=x%2;
		x/=2;
	}
	for(int i=1;i<=cnt;i++) a[y][i]=g[i];
}
bool check(int x){
	int ans=0;
	for(int i=1;i<=n;i++) if(a[i][x]==1) ans++;
	if(ans>=m) return 1;
	else return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++) cin>>x,b(x,i);
	for(int i=1;i<=30;i++) u*=2;
	for(int i=31;i>=1;i--){
		if(check(i)){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(a[j][i]==1){
					cnt++;
					for(int k=31;k>=1;k--) a[cnt][k]=a[j][k];
				}
			}
			n=cnt;v+=u;
		}
		u/=2;
	}
	cout<<v;
	return 0;
} 
