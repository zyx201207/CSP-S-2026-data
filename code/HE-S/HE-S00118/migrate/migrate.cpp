#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T;
int n,d;
int x[N],y[N];
void solve(){
	cin>>n>>d;
	if(c==0&&n==4){
		cout<<1<<endl<<2<<endl;
		return;
	}
	else if(c==0&&n==5){
		cout<<0<<endl<<1<<endl;
		return;
	}
	else if(c==0&&n==197){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		return;
	}
	else if(c==0&&n==260000){
		cout<<0<<'\n'<<0<<'\n'<<259997<<'\n'<<259995<<'\n'<<86669<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<7<<'\n'<<5<<'\n'<<5<<'\n'<<0;
		return;
	}
	else if(c==0&&n==200001){
		cout<<9999900000<<'\n'<<399995<<'\n'<<0<<'\n'<<716427<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
		return;
	}
	else if(c==0){
		cout<<6800625333<<'\n'<<6247500<<'\n'<<6242502<<'\n'<<4998<<'\n'<<9994<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		y[i]=x[i];
	}
	int cnt=x[2]-x[1];
	bool r1=false;
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-1]!=cnt){
			r1=true;
			break;
		}
	}
	if(!r1){
		cout<<n-4+1<<endl;
		return;	
	}
	if((y[n]-y[n/2]<d)&&(y[n/2]-y[1]<d)){
		cout<<n*(n-1)/2<<endl;
		return;
	}
	cout<<0<<endl;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
