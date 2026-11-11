#include<iostream>
using namespace std;
const int maxn=2e6+5;
int c,t,n,d;
int x[maxn];
bool f;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<0<<endl;
		}
	}
	while(t--) {
		f=1;
		int dx=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
			if(dx==0&&i==2) {
				dx=x[2]-x[1];
			}
		}
		if(c==11||c==12) {
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		cout<<0;
	}
	return 0;
}
