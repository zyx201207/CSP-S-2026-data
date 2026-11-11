#include<bits/stdc++.h>

using namespace std;

const int N=2e6+10;
int c,t;
long long x[N];

int main(){
	//freopen("migrate.in",'r',stdin);
	//freopen("migrate.out",'w',stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;	
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long r=x[2]-x[1];
		long long T=d/r;
		if(T<=1){
			cout<<0<<endl;
		}
		else{
			cout<<n-(T+1)<<endl;
		}
	}
	return 0;
}
