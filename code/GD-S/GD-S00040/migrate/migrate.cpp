#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum=a[i]-a[i-1];
		}
		if(d<sum*2){
			cout<<0<<endl;
		}else{
			if(d/sum*2>n)cout<<0<<endl;
			else cout<<(a[n]-a[d/sum*2])/sum+1<<endl;
		}
	}
	return 0;
}
