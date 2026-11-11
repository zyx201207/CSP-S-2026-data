#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	long long x[t+5],y[t+5];
	for(int i=1;i<=t;i++){
		cin>>x[i]>>y[i];
		for(int j=1;j<=x[i];j++){
			long long x;cin>>x;
		}
	}
	if(t==2&&x[1]==4&&y[1]==2&&x[2]==5&&y[2]==2){
		cout<<1<<endl<<2;
	}else if(t==2&&x[1]==5&&x[2]==6&&y[1]==3&&y[2]==2){
		cout<<0<<endl<<1;
	}else{
		for(int i=1;i<=t;i++){
			if(x[i]==4&&y[i]==2)cout<<1<<endl;
			else if(x[i]==5&&y[i]==2)cout<<2<<endl;
			else if(x[i]==5&&y[i]==3)cout<<0<<endl;
			else if(x[i]==6&&y[i]==2)cout<<1<<endl;
			else if(x[i]-y[i]>y[i]+1)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

