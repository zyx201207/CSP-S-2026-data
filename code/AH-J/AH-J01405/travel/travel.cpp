#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,x;
	string b,y;
	cin>>a>>b>>x>>y;
	if(a!=x)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	int f=0,r=0;
	for(int i=0;i<2;i++)
	{
		f=f*10+b[i]-'1'+1;
		r=r*10+y[i]-'1'+1;
	}
	if(f!=r)
	{
		cout<<"1000"<<endl;
		return 0; 
	}
	char z,h;
	z=b[2];
	h=y[2];
	if((z<='C'&&h>'C')||(h<='C'&&z>'C'))
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if(z=='F') z--;
	if(h=='F') h--;
	else if(abs(z-h)!=1)
	{
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<"1111"<<endl;
	
	return 0;
} 
