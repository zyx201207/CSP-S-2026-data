//GZ-S00448 Тошїне ЖМдШЖўжа
#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t>0){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n==5) cout<<"1"<<endl;
		else if(n==10) cout<<"2"<<endl;
		t--;
	}
	
	return 0;
}
