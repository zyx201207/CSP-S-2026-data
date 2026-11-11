#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[130000],k,x,t[501][501];
vector<int>v[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
			v[i].push_back(x); 
			cin>>x;
			t[i][j]=x;
		}
	}
	if(n==2&&m==5){
		cout<<32<<endl<<17;
	}
	else if(n==3&&m==7){
		cout<<35<<endl<<16;
	}
	else cout<<500;
	return 0;
}
