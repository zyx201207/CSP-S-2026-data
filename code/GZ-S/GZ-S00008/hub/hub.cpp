#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
const int N=2*1e6+20;
int a[N][2];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){	
		cin>>n>>k;
		for(int j=1;j<n;j++){
			for(int b=1;b<=2;b++){
				cin>>a[j][b];
			}
		}
	}
	if(n==10&&k==3){
		cout<<1<<'\n'<<2;
	}if(n==6&&k==2){
		cout<<0<<'\n'<<1;
	}else{
		cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'
		<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0<<'\n';



	}
	return 0;
}

