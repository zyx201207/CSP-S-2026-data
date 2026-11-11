#include<bits/stdc++.h>
using namespace std;
long long x[1000006];
int main()

{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int num=n;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i+=d){
			num--;
		}
		cout<<num;
	}
}
