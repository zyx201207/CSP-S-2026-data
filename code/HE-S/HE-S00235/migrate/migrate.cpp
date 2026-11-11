#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
long long n,d,c,c1;
void A(){
	if(d<c*2){
		cout<<0;
		return;
	}
	int k=d/c;
}
void B(){
	cout<<0;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int d,t;
	cin>>d>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		c=x[2]-x[1];
		c1=x[4]-x[3];
		if(c1==c)A();
		else B();
	}
	return 0;
}
