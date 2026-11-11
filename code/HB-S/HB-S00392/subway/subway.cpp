#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[m];
	}
	for(int i=1;i<=n;i++){
		int t,xian[100010][2],cnt=0;
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>xian[j][0]>>xian[j][1];
			cnt+=xian[j][0]+xian[j][1];
		}
		cout<<cnt;
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr
	}
	return 0;
}
