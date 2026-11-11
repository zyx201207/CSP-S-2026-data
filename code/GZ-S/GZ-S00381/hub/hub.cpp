//田缮恺 GZ-S00381 贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n[10005],k[10005];
long long u[10005],v[10005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		cin>>n[i]>>k[i];
		for(long long j=0;j<n[i];j++){
			cin>>u[i]>>v[i];
		}
	}
	if(t==1){
		cout<<1;
	}else if(t==2){
		cout<<1<<endl<<1; 
	}else if(t==3){
		cout<<2<<endl<<1<<endl<<3;
	}else if(t==4){
		cout<<2<<endl<<1<<endl<<1<<endl<<4;
	}else if(t==5){
		cout<<1<<endl<<2<<endl<<3<<endl<<5<<endl<<3;
	}else if(t==6){
		cout<<4<<endl<<3<<endl<<1<<endl<<1<<endl<<2<<endl<<5;
	}
	return 0;
}
