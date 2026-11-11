#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9+10;
ll c,n,m,d,p;
ll a[N],u[N],k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>k[i]>>a[i];
	}
	cout<<c+n+m<<endl;
	cout<<d+p;
	return 0;
}
