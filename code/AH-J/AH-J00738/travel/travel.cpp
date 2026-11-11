#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;
using LL = long long;

string a,b,x,y;
void solve(string a,string b,string x,string y){
	if(a!=x)	{
		printf("0000");
		return ;
	}
	if(b[0]!=y[0] || b[1]!=y[1]){
		printf("1000");
		return ;
	}
	if((y[2]<='C' && b[2]>'C') || (y[2]>'C' && b[2]<='C')){
		printf("1100");
		return ;
	}
	if(labs(y[2]-b[2])!=1)	{
		printf("1110");
		return ;
	}
	printf("1111");
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>x>>y;
	
	solve(a,b,x,y);


	return 0;
}
