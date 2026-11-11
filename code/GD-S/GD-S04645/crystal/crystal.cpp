#include<bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
long long c[maxn];
bool cmp(long long a,long long b){
	return a<b;
}
int half(int n,long long m){
	long long e=0;
	for(int i=2;i<=n;i++){
		e+=(long long)(i-1)*(c[i]-c[i-1]);
		if(e==m){
			int extra=0;
			for(int j=i+1;j<=n;j++){
				if(c[j]==c[i]) extra++;
			}
			return (i+extra);
		}
		if(e>m) return i-1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	sort(c+1,c+n+1,cmp);
	int ans=half(n,m);
	printf("%d",ans);
	return 0;
}
