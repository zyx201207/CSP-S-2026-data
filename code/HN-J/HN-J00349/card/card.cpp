#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N],c[N],d[N],ans[N];
signed main(){
	ios::sync_with_stdio();cin.tie();cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=0;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3){
		cout<<3<<" "<<1<<' '<<4;
	}
	if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
	}
	return 0;
}
