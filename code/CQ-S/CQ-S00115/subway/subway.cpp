#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,w[502],k[502],a[502][50002],t[502][50002],x,y,timing;
bool flag=0;
int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=0;i<n;i++){
		cin>>k[i];
		if(k[i]>2)	flag=1;
		for(long long j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		timing=0;
		cin>>x>>y;
		if(x>y)	swap(x,y);
		timing+=(w[x]+w[y]);
		if(!flag){
			for(long long i=0;i<n;i++){
				for(long long j=0;j<k[i];j++){
					if((a[i][j]==x&&a[i-1][j+1]==x)||(a[i][j]>x&&a[i][j]<y)||(a[i][j]==y&&a[i+1][j-1]==y))	timing+=t[i][j];
				}
			}
			cout<<timing<<"\n";
		}
	}
	return 0;

}

