#include <bits/stdc++.h>
using namespace std;
int a[2000001],ans,cf[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cf[i]=a[i]-a[i-1];
		}
		if(d==1){
			cout<<1<<endl;
			continue;
		}
		int t;
		for(int i=2;i<n;i++){
			if(cf[i]!=cf[i+1]){
				t=i;	
			}
		}
		if(t>4){
			if(t<2*d){
				cout<<0<<endl;
			}else if(t==2*d){
				cout<<1<<endl;
			}else{
				cout<<t-2*d+1<<endl;
			}
			continue;
		}
		if(a[4]-a[3]>d){
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12){
			if(n<2*d){
				cout<<0<<endl;
			}else if(n==2*d){
				cout<<1<<endl;
			}else{
				cout<<n-2*d+1<<endl;
			}
			continue;
		}
		if(c==13||c==14){
			int t=1;
			while(t-a[1]>d||a[n]-t>d){
				t++;
			}
			d=min(d,min(t-a[1],a[n]-t));
			if(a[t+1]-a[t-1]<=d){
				cout<<n-2*d<<endl;
				continue;
			}
		}
	}
	return 0;
}
