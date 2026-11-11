#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,nxt[N],op[N],pos[N],poss,ans[N];
map<int,int> mp;
bool ok[N]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; ++i){
		scanf("%lld",&op[i]);
		if(mp[op[i]])nxt[mp[op[i]]]=i;
		mp[op[i]]=i;
	}
	for(int i=1; i<=n; ++i){
		int st=i;
		poss=0;
		while(st<=n){
			if(nxt[st])st=nxt[st];
			else{
				if(op[st]<=m){
					if(!ok[op[st]]){
						++ans[op[st]];
						pos[++poss]=op[st];
					}
					ok[op[st]]=true;
				}
				++st;
			}
		}
		for(int j=1; j<=poss; ++j)ok[pos[j]]=false;
	}
	for(int i=1; i<=m; ++i)printf("%lld ",ans[i]);
	return 0;
} 
