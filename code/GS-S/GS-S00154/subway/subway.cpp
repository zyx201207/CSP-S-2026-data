#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,a[10000009],k;
int main(){
	int b[6767676767];
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<b[i];
	}
	return 0;
}
