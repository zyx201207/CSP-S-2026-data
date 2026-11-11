#include<bits/stdc++.h>
#define int long long
#define QWQ return 0;}
#define OoO signed main(){
using namespace std;
const int N=5e5+1;
const int PPP=1e5+1;
int n,m,sum=0;
int a[N];
int b[N];
int c[N];
int sums(){
	int maxs=-1;
	for(int i=1;i<=n;i++){
		c[b[i]+PPP]++;
		maxs=max(c[b[i]+PPP],maxs);
	}
	return maxs;
}
void soc(int z,int neng){
	if(z==n){
		sum=max(sum,sums());
		fill(c,c+N,0);
		return ;
	}
	for(int i=0;i<=neng;i++){
		b[z]=a[z]+i;
		soc(z+1,neng-i);
	}
	return ;
}
OoO
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	soc(1,m);
	cout<<sum;
QWQ
