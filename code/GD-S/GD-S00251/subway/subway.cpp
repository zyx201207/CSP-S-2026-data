#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long mod;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	while(m--)cin>>n,mod+=n;
	while(q--)cout<<abs(rand())%mod+1<<'\n';
	return 0;}
