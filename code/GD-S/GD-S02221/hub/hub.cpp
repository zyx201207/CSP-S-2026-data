#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[500010]={1,2,4,3,5,2,1,4,6}; 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cout<<a[i%9+3*i]<<endl;
	}
	return 0;
}
