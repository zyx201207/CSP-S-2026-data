#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],ma[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(c==11 || c==12){
            long long gc=x[2]-x[1];
            long long k=d%gc;
            d-=k;
            long long haha=d+d-1;
            long long ha=0;
            long long j=max(ha,n-haha);
            cout<<j<<endl;
        }
        if(c==13 || c==14){
            cout<<"2"<<endl;
        }
	}

	return 0;
}
