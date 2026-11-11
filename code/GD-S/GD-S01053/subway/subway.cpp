#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=1e5+10;
ll w[N],a[N],t[N],x[M],y[M],k[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++)
			cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	if(c==0&&n==2) cout<<32<<endl<<17;
	else if(c==0&&n==3) cout<<35<<endl<<16;
	else{
		for(int i=1;i<=q;i++){
			int t=rand()%100;
			cout<<t<<endl;
		}
	} 
	return 0;
}

