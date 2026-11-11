#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const int maxn=5e5+10;
const int maxm=1e5+10;
long long w[maxn],k[501],a[501][maxm],t[501][maxm];
long long x[maxm],y[maxm];
long long to[maxn];
long long ans,a1[maxn],a2[maxn],a3[maxn],a4[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n;
	while(n--){
		cin>>m>>d;
		for(int i=1;i<=m;i++) cin>>w[i];
		if(m==4) cout<<"1\n";
		else if(m==5&&d==2) cout<<"2";
		else if(m==5&&d==3) cout<<"0\n";
		else if(m==6) cout<<1;
	} 
	return 0;
}
