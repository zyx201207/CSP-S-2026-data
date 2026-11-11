#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	long long c,n,m,d,q;
	long long w[m],k[n],a[n][n],t[n][n],x[q],y[q],sum;
	for(long long i=0;i<m;i++){
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			sum+=a[i][j];
			sum-=t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<q;i++){
		cout<<sum<<endl;
	}
	return 0;
}
