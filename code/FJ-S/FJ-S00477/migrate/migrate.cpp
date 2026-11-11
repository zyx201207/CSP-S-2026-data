#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
#define ll long long
int c,t,n;
ll d,x[N];
/*
0 2
5 6
1 3 5 7 9
5 1
1 3 5 7 9
*/ 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		ll cha=x[1]-x[2];
		if(cha<0)cha*=-1;
		ll len=d/cha;
		if(len<=1){
			cout<<0<<'\n';
			continue;
		}
		len*=2;
		if((n-len+1)<0){
			cout<<0<<'\n';
			continue;
		}
		cout<<n-len+1<<'\n';
	}
	return 0;
}
