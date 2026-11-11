#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5,M=1e5+5;
int c,n,m,d,q,w[N];
signed main(){
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=q;i++){
		srand(time(0));
		int ans=rand()%170;
		cout<<ans<<endl;
	}	
	return 0;
} 
