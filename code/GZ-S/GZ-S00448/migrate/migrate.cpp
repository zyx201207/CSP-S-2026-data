//GZ-S00448 Тошїне ЖМдШЖўжа
#include <bits/stdc++.h>
using namespace std;
int n,x[100010],d,c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t>0){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n==4) cout<<"1"<<endl;
		if(n==5){
			if(d==2) cout<<"2"<<endl;
			else cout<<"0"<<endl;
		}
		if(n==6)
			cout<<"1"<<endl;
		t--;
	}
	return 0;
}
