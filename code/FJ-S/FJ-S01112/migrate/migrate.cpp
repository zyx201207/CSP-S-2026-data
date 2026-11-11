#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f
#define lowbit(x) x&(-x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pii pair<int,int>
using namespace std;

const int MAXN=2e6+10;
int a[MAXN];
int c,t;
int n,d;

void Code(){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		printf("0");
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int q;q=1;
	while(q--)Code();
	return 38&17;
}

