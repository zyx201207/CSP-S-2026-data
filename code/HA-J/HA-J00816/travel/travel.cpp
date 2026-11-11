#include<bits/stdc++.h>
using namespace std;
int r1,x1,r2,x2;
char r3,x3;
bool same(char r,char x)
{
	if(r>'C'&&x<='C') return 0;
	else return 1;
}
bool lin(char r,char x)
{
	if(int(r-x)==1) return 1;
	else return 0; 
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>r3>>x1>>x2>>x3;
	if(r1!=x1) cout<<"0000";
	else if(x2!=r2) cout<<"1000";
	else if(!(same(r3,x3)&&same(x3,r3))) cout<<"1100";
	else if(!(lin(r3,x3)||lin(x3,r3))) cout<<"1110";
	else cout<<"1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
