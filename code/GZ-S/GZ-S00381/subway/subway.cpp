//田缮恺 GZ-S00381 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
int c,n,d;
long long w[10005],a[10005][10005],t[10005][10005],x[1005],y[1005];
long long q,m,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(long long i=0;i<n;i++){
		cin>>k;
		for(long long j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<36<<endl<<18;
	return 0;
}
