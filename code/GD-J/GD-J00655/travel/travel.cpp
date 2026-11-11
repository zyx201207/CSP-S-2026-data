#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int as1,as2=1,as3,as4;
	cin>>a>>b>>c>>d;
	as1=a==c;
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i]) as2=0;
	}
	as2=as1&&as2;
	as3=(b[2]<='C') == (d[2]<='C');
	as3=as3&&as2;
	as4=abs(b[2]-d[2])==1 && as3;
	cout<<as1<<as2<<as3<<as4;
	return 0;
} 
