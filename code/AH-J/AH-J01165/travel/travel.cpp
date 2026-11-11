#include<bits/stdc++.h>
using namespace std;

string x1,x2,r1,r2;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>x1>>x2>>r1>>r2;
	
	int a=0,b=0,c=0;
	if(x1==r1) a=1;
	if(a==1&&(x2[0]-'0')*10+(x2[1]-'0')==((r2[0]-'0')*10+(r2[1]-'0'))) b=1;
	if(a==1&&b==1&&((x2[2]>='D'&&r2[2]>='D')||x2[2]<='C'&&r2[2]<='C')) c=1;
	
	cout<<a<<b<<c;
	if(a==1&&b==1&&c==1){
		if((x2[2]+1)==r2[2]||(x2[2]-1)==r2[2]) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	return 0;
	
}
