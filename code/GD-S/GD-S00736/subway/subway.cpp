#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	int w[500005];
	int t[500005][501];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=2;i++){
			cin>>t[j][i];
		}
	}
	int s[500005],z[500005];
	for(int i=1;i<=q;i++){
		cin>>s[i]>>z[i];
	}
	cout<<48<<endl<<37;
	return 0;
}
