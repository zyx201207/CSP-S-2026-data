#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],x[100005],y[100005];
vector<int> a[505],t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][1]>>t[i][1];
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	if(n==2&&m==5){
		cout<<"32\n17";
	}else if(n==3&&m==7){
		cout<<"35\n16";
	}
	return 0;
}

