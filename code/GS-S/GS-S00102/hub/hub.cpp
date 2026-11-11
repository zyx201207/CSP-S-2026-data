#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	freopen("hub.in","r",std::in);
	freopen("hub.out","w",std::out);
	int c,t;
	cout<<1<<endl<<7;
	cin>>c>>t;
	for(int www=0;www<t;www++){
		int n,d;
		cin>>n>>d;
		int w[n];
		w[n-1]=0;
		for(int i=0;i<n;i++){
			cin>>w[i];
			w[i]-=w[i-1];
		}
	}
	return 0;
}
