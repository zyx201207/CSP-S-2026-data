#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a[1145],b[1145];
	cin>>c>>t;
	while(t--){
		cout<<a[b[a[t]+c]]<<endl;
	}
	return 0;
}
