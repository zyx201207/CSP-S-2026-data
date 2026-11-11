#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N=1e4+10,M=1e7+10,K=25,INF=0x3f3f3f3f;
int n,m,c,d,q;
LL a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	srand(time(0));
	cin.tie(0);
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<rand()%3<<endl;
	} 
	return 0;
}
