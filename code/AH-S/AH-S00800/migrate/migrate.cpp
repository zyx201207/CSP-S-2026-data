#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005],n,d;
bool check2(){
	long long t=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=t)return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(check2()){
			if(d<=a[2]-a[1]||d>=a[n]-a[1]){
				cout<<0<<endl;
			}
			else{
				long long op=d/(a[2]-a[1])+d/(a[2]-a[1])-1;
				cout<<n-op<<endl;
			}
		}
		else {
			cout<<0<<endl;
		}
	}
	return 0;
}
