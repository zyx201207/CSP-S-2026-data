#include<bits/stdc++.h> 
#define int long long
using namespace std;
int c,n,m,d,q;
int const M=5e5+5,N=5e2+2;
int w[M];
struct sub{
	int k,a[M],t[M];
}s[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<q;i++){
		for(int j=0;j<m;j++){
			cin>>w[j];
		}
		cin>>s[i].k;
		for(int b=0;b<k;b++){
			cin>>s[b].a>>s[b].t;
		}
	}
	return 0;
}
