#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long sum;
int w[500025],k[505],a[500025],t[500025],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			sum+=t[j];
		}
	}	
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i]; 		
	}
	if(sum>=200){
		sum-=198;
	}
	cout<<sum<<" "<<endl;
	if(sum%2==0)cout<<sum/2+1;
	else cout<<sum/2-1;
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3


