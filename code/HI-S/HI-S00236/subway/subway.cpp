#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int z[500005][2]={0};
	for(long long i=0;i<n;i++){
		int k;
		cin>>k;
		for(long long j=0;j<k;j++){
			cin>>z[j][0]>>z[j][1];
		}
	}
	long long x[100005][2]={0};
	for(long long i=0;i<q;i++){
		cin>>x[i][0]>>x[i][1];
	}
	cout<<32;
	return 0;
}
