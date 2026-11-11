#include<bits/stdc++.h>
#define int ll
using namespace std;
using ll=long long;
const int M=5e5+5,N=505;
int c,n,m,d,q,T=-1;
int w[M],a[N][N],t[N][N];
bool A=1,B=1;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		if(k>2)A=0;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(~T)T=t[i][j];
			else if(T!=t[i][j])B=0;
		}
	}
	if(A){
		while(q--){
			int x,y;cin>>x>>y;
			
		}	
	}else if(B){
		while(q--){
			int x,y,cnt;cin>>x>>y;
			for(int i=x;i<=y;i++){
				cnt+=w[i]+T;
			}
			cout<<cnt<<'\n';
		}
	}
	
	return 0;
}
