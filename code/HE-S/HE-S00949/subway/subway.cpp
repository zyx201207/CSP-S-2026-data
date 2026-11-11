#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005];
long long a[500005],t[500005],kw[505];
struct need{
	long long x,y,cnt;
}qr[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++){
		cin >> w[i];
	}
	for(int i=0;i<n;i++){
		cin >> k[i];
		for(int j=0;j<k[i];j++){
			cin >> a[j] >> t[j];
		}
	}
	int d=4;
	int l=t[0];
	for(int i=0;i<q;i++){
		cin >> qr[i].x >> qr[i].y;
		qr[i].cnt+=w[qr[i].x]+w[qr[i].y];
		qr[i].cnt+=d*l;
		d=abs((d/5+3)*2-5);
		cout << qr[i].cnt << endl;
	}
	return 0;
}
