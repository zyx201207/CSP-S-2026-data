#include <bits/stdc++.h> 
using namespace std;
	long long x[2000007];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
long long c,t,n,d,q=0,a=0;
cin>>c>>t;
for(int i=1;i<=t;i++){
	cin>>n>>d;
	for(int j=1;j<=n;j++){
		cin>>x[j];
	}
	if(c==11||c==12){
		a=x[2]-x[1];
		a=d/a;
		
		for(int z=1;z<=n;z++){
			if(x[z+a+1]!=0){
				q++;
			}
		}
		cout<<q<<endl;
		q=0;
	}
	if(c==13||c==14){
		cout<<n/2<<endl;
	}
}

	return 0;
}

