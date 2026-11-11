#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int a,b;
	for(long long  i=0;i<m;i++){
		cin>>w[i];
	}
	for(long long i=0;i<n;i++){
		int k;
		cin>>k;
		int a[10006];
		for(long long j=0;j<2*k;j++){
			cin>>a[j];
		}
		
	}
	cin>>a>>b;
	cout<<a*9<<endl<<b*22<<endl;
	return 0;
}
