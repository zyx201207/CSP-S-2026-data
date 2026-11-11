#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	int x=a[m],maxn=0;
	for(int i=31;i>=0;i--){
		unsigned long long s=1<<i;
		if(a[m]>s){
			maxn=i+1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		unsigned long long s=1<<maxn;
		if(a[i]>=s){
			int k=a[i];
			k>>=maxn;
			k<<=maxn;
			a[i]-=k;
		}
	}
	sort(a+1,a+n+1,cmp);
	unsigned long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	printf("%llu",ans);
	return 0;
} 
