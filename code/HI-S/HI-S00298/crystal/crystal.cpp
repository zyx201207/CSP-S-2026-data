#include<bits/stdc++.h>
#define afor(i,x,y) for(int i=(x);i<=(y);i++)
#define bfor(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,j,ans;
ll m,si,sj,a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	afor(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	afor(i,1,n) {
		si+=a[i];
		while(a[i]*(i-j)-si+sj>m) sj+=a[++j];
		ans=max(ans,i-j);
	}
	printf("%d",ans);
	return 0;
}
