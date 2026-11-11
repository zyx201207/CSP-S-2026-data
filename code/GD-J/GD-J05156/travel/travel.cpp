#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int k1,k2;
bool t1,t2,t3,t4;
int main(){
	cin>>a>>x>>b>>y;
	k1=(x[0]-'0')*10+(x[1]-'0');
	k2=(y[0]-'0')*10+(y[1]-'0');
	if(a==b)t1=1;
	if(k1==k2)t2=1;
	if(x[2]<='C'&&y[2]<='C'||x[2]>='D'&&y[2]>='D')t3=1;
	if(abs(x[2]-y[2])==1)t4=1;
	if(t1==0)t2=0,t3=0,t4=0;
	if(t2==0)t3=0,t4=0;
	if(t3==0)t4=0;
	cout<<t1<<t2<<t3<<t4;
	return 0;
}
