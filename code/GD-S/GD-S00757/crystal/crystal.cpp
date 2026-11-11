#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=1e6+5;
ll a[MAXN];
int n;ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1;ll pr=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		while(l<i&&(i-l)*a[i]-pr>m){
			pr-=a[l];
			l++;
		}
		pr+=a[i];
		maxn=max(maxn,i-l+1);
	}
	printf("%d\n",maxn);
} 
