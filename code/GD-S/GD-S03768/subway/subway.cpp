#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100000000],d,m,q,w[10000000];
int c,t;
bool pd=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		cout<<i+n<<"\n";
	}
	return 0;
}
