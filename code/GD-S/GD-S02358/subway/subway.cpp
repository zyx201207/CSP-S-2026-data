#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[500010];
int a[500010];
int t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cout<<n*m+d+q<<endl<<n+m+d/q<<endl;
	return 0;
}
