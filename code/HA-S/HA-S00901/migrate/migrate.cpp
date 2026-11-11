#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+114514;
ll n,c,t,dao[N],d;
int main(){
	freopen("migrate.in.txt","r",stdin);
	freopen("migrate.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>dao[N];
		}
		if(dao[2]-dao[1]<d)
			cout<<n/d-1;
		else
			cout<<n/d%d+1;
	}
	return 0;
} 

