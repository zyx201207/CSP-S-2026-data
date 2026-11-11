#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x;
		cout<<n-1<<"\n";
	}
	return 0;
}
