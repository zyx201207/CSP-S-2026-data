#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n;
long long int m,a[MAXN],c[MAXN],len=1,l=1,r=2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=a[i]+c[i-1];
	while(r<=n){
		int op=c[r]-c[l-1],le=r-l+1;
		if(le*a[r]-op<=m){
			len++;
			r++;
		}
		else {
			l++;
			r++;
		}
	}
	printf("%d",len);
	return 0;
}
