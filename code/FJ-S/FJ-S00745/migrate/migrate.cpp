#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],Ad;
bool flag;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		flag=true;
		cin>>n>>d>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
			if(i==2)
				Ad=x[2]-x[1];
			else if(Ad!=x[i]-x[i-1])
				flag=false;
		}
		if(flag){
			if(n<d/Ad*2||d<=Ad)
				cout<<0<<endl;
			else
				cout<<n-d/Ad*2+1<<endl;
		}
	}
	return 0;
} 
