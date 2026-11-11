#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=5e5+5;
ll n,m,a[ma],nxt[ma],ans[ma];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		int r=0;
		memset(nxt,-1,sizeof(nxt));
		for(int i=k;i<=n;i++){
			if(r!=a[i])nxt[r]=a[i];
			r=a[i];
			int x=r;
			while(x!=-1){
				int sto=x;
				x=nxt[x];
				nxt[sto]=-1;
			}
		}
		int x=0;
		while(x!=-1){
			ans[x]++;
			x=nxt[x];
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
*/
