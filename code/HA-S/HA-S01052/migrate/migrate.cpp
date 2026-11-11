#include<bits/stdc++.h>
using namespace std;
long long c,y,n,d,gg;
int a[10000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>y;
	for(int i=1;i<=y;i++){
		gg=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
			gg=gg+a[i];
		}
		if(gg<=0){
			cout<<-gg;
		}else{
			cout<<gg/5-1;
		}
	}
	return 0;
}
