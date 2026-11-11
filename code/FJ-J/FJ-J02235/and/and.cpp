#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+50;
int m,n;
ll a[N];
bool b[N][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a[i]);
	sort(a+1,a+n+1);
	printf("%lld",a[n-m+1]);
	return 0;
}