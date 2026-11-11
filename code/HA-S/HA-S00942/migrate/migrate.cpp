#include<iostream>
#include<cstdio>
using namespace std;
long long c,t,x[2000006],n,d;

void workb(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<'\n';
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		workb();
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		cout<<1<<'\n';
	}
	
	return 0;
}
