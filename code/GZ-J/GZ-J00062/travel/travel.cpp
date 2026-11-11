//GZ-J00062 毕节七星关东辰实验学校 徐海荣搏 
#include<iostream>
using namespace std;
bool A=false;
bool B=false;
bool C=false;
bool D=false;
int main()
{
	int a,b,x,y;
	char c,z;
	cin>>a>>b>>c>>x>>y>>z;
	if(a == x) A=true;
	if(b == y) B=true;
	if(c-'A'<3 && z-'A'<3 || c-'A'>3 && z-'A'>3) C=true;
	if(c-z == '1' || (c+1)-z == 0) D=true;
	if(A) cout<<'1';
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(B) cout<<'1';
	else 
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(C) cout<<'1';
	else cout<<'0';
	if(c=='C' && z=='D' || c=='D' && z=='C') cout<<'0';
	else if(D) cout<<'1';
	else cout<<'0';
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}
