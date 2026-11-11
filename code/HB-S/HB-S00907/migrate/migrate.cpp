#include<bits/stdc++.h>
using namespace;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		long long n,d,x[200010]=}{0},cnt=0;
		cin>>n>>d;
		for(long long i=0;i<n;i++){
			cin>>x[i];
		}
		long long m=2,y=0,cnt=0;
		while(m<n){
			for(long long i=m;i<n;i++){
				y=x[i]-x[i-m];
				if(d<y&&y<2*d)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
