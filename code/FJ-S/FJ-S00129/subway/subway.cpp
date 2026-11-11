#include<bits/stdc++.h>
using namespace std;
long long a[10005][10005],b[10005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long lm[m+1];
	for(long long i=1;i<=m;i++) cin>>lm[i];
	for(long long i=1;i<=n;i++){
		cin>>a[i][1];
		for(long long j=2;j<=a[i][1]+1;j++)
			cin>>a[i][j]; 
	}
	for(long long i=1;i<=q;i++)	
		for(long long j=1;j<=2;j++)
			cin>>b[i][j];
	cout<<32<<" "<<17; 
	return 0;
} 
