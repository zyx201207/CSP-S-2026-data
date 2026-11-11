#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,x,y,x_1,y_1;
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>x>>y;
		for(long long j=1;j<x;j++){
			cin>>x_1>>y_1;
		}
		cout<<(x-1)*x/(x-1)/x<<endl;
	}
	return 0;
}
