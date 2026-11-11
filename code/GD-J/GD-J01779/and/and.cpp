#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int n,m,k,a[N],maxn,t;
int hs(int id,int ans){
	int b=0,z=0,m=1;
	while(id&&ans){
		if(id%2==1&&ans%2==1){
			if(b!=0){
				for(int i=1;i<=b;i++)
					m*=2;
				z+=m;
				m=1;
			}
			else if(b==0){
				z+=1;
			}
		}
		id>>=1;
		ans>>=1;
		b++;
	}
	return z;
}
void dfs(int x,int y,int bushu){
	if(bushu==m) {maxn=max(y,maxn);return ;}
	if(x==n+1) return ;
	dfs(x+1,hs(y,a[x]),bushu+1);
	dfs(x+1,y,bushu);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,2097151,0);
	cout<<maxn;
	return 0;
}
