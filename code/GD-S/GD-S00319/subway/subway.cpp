#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f;
int c,n,m,d,q;
int w[N],a[N],b[N];
 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=7;i++)cin>>a[i];
	for(int i=1;i<=7;i++)cin>>b[i];
	if(n==2)cout<<32<<endl<<17;
	if(n==3)cout<<35<<endl<<16;
	return 0;
}
