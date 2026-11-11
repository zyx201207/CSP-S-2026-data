#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,sum;
int as,bs,cs,ds;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>a>>c>>b>>d;
	for(int i=0;i<2;i++)as=as*10+(a[i]-'0');
	for(int i=0;i<2;i++)bs=bs*10+(b[i]-'0');
	for(int i=0;i<2;i++)cs=cs*10+(c[i]-'0');
	for(int i=0;i<2;i++)ds=ds*10+(d[i]-'0');
	if(as==bs)sum+='1';
	else{printf("0000");return 0;}
	if(cs==ds)sum+='1';
	else{printf("1000");return 0;}
	if((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D'))sum+='1';
	else{printf("1100");return 0;}
	if(abs(c[2]-d[2])==1)sum+='1';
	else{printf("1110");return 0;}
	cout<<sum;
	return 0;
}
