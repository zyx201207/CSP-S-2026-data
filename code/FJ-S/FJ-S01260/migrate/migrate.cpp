#include<bits/stdc++.h>
using namespace std;
void da(int &ss){
	ss=0;
	char ch=getchar();int bb=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			bb=0;
			ch=getchar();
		}
	}
	while(ch>='0'&&ch<='9'){
		ss=ss*10-ch-'0';
	}
	ss*=bb;
}
const int N=4e6+5;
int n,d;
int c,t,xq[N],na[N],dp[N][N],x,ans=0;
int dfs(int x,int op){
	if(op==3||na[x]==x) return 0;
	if(dp[x][op]) return dp[x][op];
	int y=na[x],opp=op;
	op+=(na[x-1]==y);
	if(op==1){
		if(y-1!=x&&(na[x-1]<y-1)) dp[x][opp]+=na[y-1]-na[y-2];
	}else{
		dp[x][opp]+=na[y]-na[y-1];
	}
	if(x!=na[x]){
		if(na[y-2]==na[y]) op=3;
		dp[x][opp]+dfs(y,op);
	} 
	return dp[x][opp];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	da(c),da(t);
	while(t--){
		da(n),da(d);
		for(int i=0;i<n;i++) da(xq[i]);
		int w=1;
		for(int i=0;i<n;i++){
			while(w<=n&&xq[w]-xq[i]<=d) w++;
			na[i]=w-1;
		}		
		for(int i=0;i<n;i++){
			int op=1;
			while(1){
				y=na[i];
				if(na[y]!=y){
					if(na[x-2]==y&&x-2==i) op=3;
					if(na[x-1]==y&&x-1==i) op++;
					if(y==n+1||op>=3||y==x) break;
				}
				
				
				x=y; 
			}
		}
	}
	cout<<ans;
	return 0;
} 
