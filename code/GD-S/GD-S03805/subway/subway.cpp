#include <bits/stdc++.h>
using namespace std;
const long long N=1e8;
long long w[N],a[N][1000000],t[N][1000000];

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q,sum=0;
	cin>>c>>n>>m>>d>>q;
	
	for(long long i=1;i<=m;i++){
		cin>>w[i]; 
		sum+=w[i];
	}
	long long ki;
	cin>>ki;
	int a[n][ki+2];
	for(auto p:a){
		scanf("lld%",a);scanf("lld%",t);
	}
	

	cout<<sum;
	
	
	
	return 0;
}






 
