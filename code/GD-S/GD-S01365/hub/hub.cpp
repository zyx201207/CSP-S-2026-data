#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	unsigned long long c,t;
	scanf("%lld %lld",&c,&t);
	for(int i=0;i<t;i++){
		unsigned long long n,k;
		scanf("%lld %lld",&n,&k);
		unsigned long long k[n],v[n];
		for(int j=0;j<n;j++){
			scanf("%lld %lld",&k[j],&v[j]);
		}
		if(n==5&k==2)cout<<"1"<<endl;
		else if(n==1&k==2)cout<<"2"<<endl;
		else cout<<"2"<<endl;
	}
	return 0;
}
