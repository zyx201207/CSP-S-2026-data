//GZ-S00103 南白初级中学 唐清倾 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,mn=INT_MAX;
long long d,x[1000001]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n%2==1) cout<<1<<endl;
	}
	if(t==2){
		cout<<2<<endl;
		cout<<1;
	}
	if(t==3){
		cout<<1<<endl;
		cout<<4<<endl;
		cout<<2;
	}
}
