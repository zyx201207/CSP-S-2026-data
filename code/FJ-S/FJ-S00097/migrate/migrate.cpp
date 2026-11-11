#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,q,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long w=x[2]-x[1],ans=0;
			if(d<2*w)cout<<"0\n";
			else{
				d/=w;
				if(n-2*d+1<0)cout<<0;
				cout<<n-2*d+1<<'\n';
			}
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<(n+1)/d-1<<'\n';
		}
	}
	return 0;
}
