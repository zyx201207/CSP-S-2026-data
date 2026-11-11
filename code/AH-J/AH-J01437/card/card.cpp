#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int p[300005];
int t[300005];
int stk[300005];
int u=1,d=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		memset(stk,0,sizeof(stk));
		u=1,d=1;
		//while(!stk.empty())stk.pop();
		for(int j=i;j<=n;j++){//p[j]
			for(int k=j;k<=u;k++){
				if(stk[k]==p[j]){
					for(int l=j;l<=u;)u--;
					break;
				}
			}
			stk[u++]=p[j];
		}
		while(u!=d){
			t[stk[u--]]++;
		}

	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}

	return 0;
}
