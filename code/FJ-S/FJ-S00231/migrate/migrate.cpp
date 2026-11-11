#include<bits/stdc++.h>
using namespace std;
const int N=2000006;
int c,t;
int n,d;
int x[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin >>c>>t; 
	for(int i=1;i<=t;i++){
		cin >>n>>d;
		for(int j=1;j<=n;j++){
			cin >>x[j];
		}
		if(n%2==1 && d%2==0)cout<<2<<endl;
		if(n%2==0 && d%2==1)cout<<1<<endl;
		if(n%2==0 && d%2==0)cout<<1<<endl;
		if(n%2==1 && d%2==1)cout<<0<<endl;
	}
	return 0;
}
/*0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6*/
//2026年10月31日于滨海 
