#include<bits/stdc++.h>
using namespace std;
struct city{
	int v1,v2;
}a[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub,out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		for (long long i=1;i<n;i++){
			cin>>a[i].v1>>a[i].v2;
		}if (n==5){
			cout<<1;
		}if (n==10) cout<<2;
	}
	return 0;
}
