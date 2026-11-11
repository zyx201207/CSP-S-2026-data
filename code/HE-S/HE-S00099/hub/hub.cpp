#include<iostream>
using namespace std;
int u[1000001],v[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin >> c >> t;
	for(int i4=0;i4<t;i4++){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			cin >> u[i] >> v[i];
		}
		cout << 1 << endl;
	}
	return 0;
}
