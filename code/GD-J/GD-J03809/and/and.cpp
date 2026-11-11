#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
void dg(int x,int y,long long s){
	if(y==m){
		maxx=max(maxx,s);
	}
	for(int i=x+1;i<=n;i++){
		dg(i,y+1,s&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		dg(i,1,a[i]);
	}
	printf("%lld",maxx);
	return 0;
}
