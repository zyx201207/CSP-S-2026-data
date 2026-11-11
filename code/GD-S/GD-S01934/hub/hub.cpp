#include<bits/stdc++.h>
using namespace std;
int c,t;
#define ll long long
ll n,k;
ll a[10084][10];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		printf("%lld\n",(n+k));
	}
	return 0;
}
