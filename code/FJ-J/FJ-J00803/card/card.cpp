#include<bits/stdc++.h>
using namespace std;
long long n,m,ji[300005],x[500005];
void dfs(long long w){
	if(w>n) return;
	long long qu=0;
	for(int j=n;j>w;j--){
    	if(x[w]==x[j]){
    		qu=j;
    		break;
		}
	}
	ji[x[w]]++;
	if(qu==0) qu=w;
	dfs(qu+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=n;i>=1;i--){
		dfs(i);
	}
	for(int i=1;i<=m;i++) cout<<ji[i]<<" "; 
	return 0;
}
