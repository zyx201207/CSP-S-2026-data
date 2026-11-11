#include<bits/stdc++.h>
using namespace std;
long long z,x,b;
string c,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>z;
	for(int i=1;i<=3;i++)cin>>c[i];
	cin>>x;
	for(int i=1;i<=3;i++)cin>>v[i];
	if(z==x)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	} 
	if(v[1]==c[1]&&c[2]==v[2]){
		cout<<1;	
	}
	else cout<<0;
	if((((c[3]=='A'||c[3]=='B'||c[3]=='C')&&(v[3]=='A'||v[3]=='B'||v[3]=='C'))&&(v[1]==c[1]&&c[2]==v[2]))||(((c[3]=='D'||c[3]=='E')&&((v[3])=='D'||v[3]=='E'))&&(v[1]==c[1]&&c[2]==v[2]))){
		b=1;
		cout<<1;
	}
	else cout<<0;
	if(b==1&&abs(c[3]-v[3])==1)cout<<1;
	else cout<<0;
	return 0;
}