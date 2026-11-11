#include<bits/stdc++.h>
using namespace std;
long long c,n,d,t,a[2000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<n;i++) cin>>a[i];
		cout<<n/d<"\n";
	}
	return 0;
}
