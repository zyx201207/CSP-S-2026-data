#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[500],k[500],sum=0;
	int a[500001],t[500001],x[100001],y[100001];
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++){
		cin >> w[i];
		sum=sum+w[i];
	}
	for(int i=0;i<n;i++){
		cin >> k[i];
		for(int j=0;j<2*k[i];j++){
			cin >> a[j] >> t[j];
			sum=sum+t[i];
		}
	}
	for(int i=0;i<q;i++){
		cin >> x[i] >> y[i];
		cout << sum << endl;
	}
	return 0;
}
