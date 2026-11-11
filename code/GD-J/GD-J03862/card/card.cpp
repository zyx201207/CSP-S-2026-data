#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,cnt,d[N],b[N];
void er(long long x,long long j){
	for(long long i=x;i<=j;i++)
		d[i]=-1;
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		er(1,m);
		for(long long j=i;j<=n;j++){
			if(d[a[j]]!=-1) er(d[a[j]],j-1);
			d[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(d[j]!=-1) b[j]++;
	}
	for(int i=1;i<=m;i++) 
		printf("%lld ",b[i]);
	return 0;
}
