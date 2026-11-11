#include<bits/stdc++.h>
using namespace std;
long long C,t,n,d,B;
long long x[2000005],a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		a[2]=x[2]-x[1];
		long long cha=x[2]-x[1];
		for(int i=3;i<=n;i++){
			a[i]=x[i]-x[i-1];
			if(a[i]!=cha){
				B=1;
				break;
			}
		}
		if(B==0){
			int num=d/a[2];
			if(num<2){
				cout<<0<<"\n";
				continue;
			}
			else{
				cout<<n-num-1<<"\n";
				continue;
			}
		}
		else{
			cout<<0<<'\n';
			return 0;
		}
	}
	return 0;
}
