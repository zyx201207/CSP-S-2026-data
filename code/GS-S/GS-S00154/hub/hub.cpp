#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,a[10000009],k;
int main(){
	int b[6767676767];
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>d;
		for(int j=1;j<=m;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;
}
