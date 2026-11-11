#include<bits/stdc++.h> 
using namespace std;
int C_R,C_X,zr,zx,r,x;
string Z_R,Z_X;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> C_R >> Z_R >> C_X >> Z_X;
	if(C_R == C_X)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	zr=int(Z_R[0]-'0')*10+int(Z_R[1]-'0');
	zx=int(Z_X[0]-'0')*10+int(Z_X[1]-'0');
	if(zr==zx)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if(Z_R[2]=='A')
	{
		r=1;
	}
	if(Z_R[2]=='B')
	{
		r=2;
	}
	if(Z_R[2]=='C')
	{
		r=3;
	}
	if(Z_R[2]=='D')
	{
		r=4;
	}
	if(Z_R[2]=='F')
	{
		r=5;
	}
	if(Z_X[2]=='A')
	{
		x=1;
	}
	if(Z_X[2]=='B')
	{
		x=2;
	}
	if(Z_X[2]=='C')
	{
		x=3;
	}
	if(Z_X[2]=='D')
	{
		x=4;
	}
	if(Z_X[2]=='F')
	{
		x=5;
	}
	if(x<=3&&r<=3 || x>=4&&r>=4)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
		cout << 0;
		return 0;
	}
	if(x-r==1||r-x==1)
	{
		cout << 1; 
	} 
	else
	{
		cout << 0;
	}
	return 0;
}
