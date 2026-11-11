#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x[500005][2],k,k1,k2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cout<<c<<n<<m<<d<<q;
	for(int i=1;i<=m;i++){
		cin>>x[i][0];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>k1>>k2;
			x[k1][1]=max(x[k1][1],k2);
		}
	}
	for(int i=0;i<q;i++){
		cin>>k1>>k2;
		cout<<x[k1][1]+x[k1][0]+x[k2][0]+x[k2][1];
		if(i<q-1)cout<<endl;
	}
	
	return 0;
	
}
