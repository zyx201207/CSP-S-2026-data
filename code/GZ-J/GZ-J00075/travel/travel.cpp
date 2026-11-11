//GZ-J00075,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
void ji(){
	ll a,b,f=0;
	str c,d;
	cin>>a>>c>>b>>d;
	if(a!=b)cout<<"0000";
	if(a==b)
	{
		cout<<1;
		if(c[0]==d[0]&&c[1]==d[1])
		{
			cout<<1;
			if((c[2]<'D'&&d[2]<'D')||(c[2]>='D'&&d[2]>='D')){
			cout<<1;
			f=1;
			if(f&&abs(c[2]-d[2])==1)cout<<1;
			else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll t=1;//cin>>t;
	while(t--){
		ji();
	} 
	return 0;
} 
