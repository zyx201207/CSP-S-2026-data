#include<bits/stdc++.h>
using namespace std;
struct qq{
	int num;
	int t;
}a[505][505]; 
int x[100005],y[100005],k[505];
int w[500005];
int b[305][305];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];i++){
			cin>>a[i][j].num>>a[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	long long sum=0;
	int l=2;
	for(int i=1;i<=q;i++){
		sum=0;
		sum+=(w[x[i]]+a[x[i]][x[i]].t);
		while(l!=x[i]){
			sum+=a[x[i]][l].t;
			l++;
		}
		sum+=w[l];
		cout<<sum<<"\n";
	}
	return 0;
} 
//Oct31==Dec25?
