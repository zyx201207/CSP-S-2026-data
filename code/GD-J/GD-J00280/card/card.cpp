//100+100+100+48=348
//不要挂分
//可以反向挂分(bushi) 
#include<bits/stdc++.h>
using namespace std;
#define MAXN 600100
int n,m,a[MAXN],sum[MAXN],pos[MAXN]/*维护a[i]是否在栈中出现及其位置*/;
int stk[MAXN],topp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		//栈中的数是其下标 
		memset(pos,0,sizeof pos);
		for(int j=i;j<=n;j++){
			if(pos[a[j]]){
				while(topp>pos[a[j]]){
					pos[ a[ stk[topp] ] ]=0;
					topp--;
				}
			}
			else stk[++topp]=j,pos[a[j]]=topp;
		}
		while(topp){
			sum[a[stk[topp]]]++,topp--;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
} 
