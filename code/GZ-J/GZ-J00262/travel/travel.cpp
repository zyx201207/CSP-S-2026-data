//GZ-J00262遵义四十九中学 万昱丞
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c,b,d;
	cin>>a>>c>>b>>d;
	int n=c[0]+c[1],m=d[0]+d[1],i=c[2],j=d[2],q=1;
	if(a==b)cout<<1;
	else{
		cout<<0;
		q=0;
	}
	if(n==m&&q==1)cout<<1;
	else{	
		cout<<0;
		q=0;
	}
	if(i>67&&j<68){
		cout<<0;
		q=0;
	}
	else if(j>67&&i<68||q==0){
		cout<<0;
		q=0;
	}
	else cout<<1;
	if(i+j==132||q==0)cout<<0;
	else cout<<1;
	return 0;
}
