#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[m+1],k[n+1],a[n+1][1005],b[n+1][1005];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int sum;
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>b[i][j];
			sum=a[i][j];
		}
	}
	int x,y;
	cin>>x>>y;
	if(x>=y){
		cout<<(x-y)*sum<<endl;
	}
	else{
		cout<<(y-x)*sum<<endl;
	}
	return 0;
}
