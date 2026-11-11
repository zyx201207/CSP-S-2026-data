#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		long long l;
		bool f=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				l=a[i]-a[i-1];
			}else if(i>=3){
				if(a[i]-a[i-1]!=l) f=false;
			}
		}
		if(f==true){
			if(d<2*l) cout<<0<<endl;
			else{
				long long k=d/l+2;
				if(n>=k) cout<<n-k+1<<endl;
				if(n<k) cout<<0<<endl;
			}
		}
	}
} 
