#include <bits/stdc++.h>
using namespace std;
int sum[25],a[200005],e[200005],c=0,n,m,fd=0;
bool ikun[200005][25];
int dfs(int s,int o){
	if(o==m) return 100663295;
	if(m-o>c-s+1) return 0;
	return max(dfs(s+1,o+1)&e[s],dfs(s+1,o));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int oi=1,aa=a[i];
		while(aa>0){
			ikun[i][oi]=aa%2;
			if(ikun[i][oi]) sum[oi]++;
			aa/=2;
			oi++;
		}
	}
	for(int i=20;i>=0;i--){
		if(sum[i]>=m){
			fd=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(ikun[i][fd]){
			e[++c]=a[i];
		}
	}
	cout<<dfs(1,0);
	return 0;
}
