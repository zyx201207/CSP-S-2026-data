#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e6+10;
int c,t,n,d,k;
int x[N];
bool flag=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			if(x!=0&&x[j]!=x[j-1]) flag=false;
		}
		if(flag){
			k=x[2]-x[1];
			d=(d/k)*k;
			if(d<k) cout<<0<<endl;
			else{
				cout<<(n-(x[n]-x[1])/d-d/k)*(d/k)<<endl;
			}
		}
		else cout<<0;
	}
	return 0;
} 
