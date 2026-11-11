#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,xb;
}b[500005];
bool cmp(node u,node v){
	return u.x<v.x;
}
long long t[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500005];
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i].x=a[i],b[i].xb=i;
	}
	stable_sort(b+1,b+n+1,cmp);
	for(int i=1;i<n;i++){
		if(b[i+1].x==b[i].x) t[b[i].xb]=b[i+1].xb;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[j]==0) ans[a[j]]++;
			else j=t[j]-1;
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
