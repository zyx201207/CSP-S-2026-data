#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,a,cn,b;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cn=0;
		b=0;
		cin>>n>>k;
		for(int i=1;i<=2*(n-1);i++)cin>>a;
		n=(n-1)/2;
		while(cn<n){
			b++;
			cn=(b*2-1)*2+k-2;
		}
		cout<<b<<endl;
	}
	return 0; 
}
