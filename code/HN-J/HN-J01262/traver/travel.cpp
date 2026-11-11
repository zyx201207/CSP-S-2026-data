#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",std);
	freopen("travel.out","w",std);
	int a,b;
	char c[5]={},d[5]={};
	cin>>a>>c>>b>>d;
	if(a!=01 and a!=16 and b!=01 and b!=16)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	if(c-d<=4 or d-c>=-4)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	if(c-d<=1 or d-c>=-1)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
} 
