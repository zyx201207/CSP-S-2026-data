#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll change()
{
	char a,b;
	cin>>a>>b;
	return (a-'0')*10+(b-'0');
} 
bool left(char c)
{
	if(c<='C'&&c>='A') return 1;
	return 0;
}
bool right(char c)
{
	if(c<='F'&&c>='D') return 1;
	return 0; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll a_num=change();
	ll a_p=change();
	char A;
	cin>>A;
	ll b_num=change();
	ll b_p=change();
	char B;
	cin>>B;
//	cout<<a_num<<' '<<a_p<<A<<'\n';
//	cout<<b_num<<' '<<b_p<<B<<'\n';
	bool bo1=(a_num==b_num),bo2=(a_p==b_p);
	bool bo3=0,bo4=0;
	if(left(A)&&left(B)) bo3=1;
	if(right(A)&&right(B)) bo3=1;
	if((abs(A-B)==1)&&A!='D'&&B!='D') bo4=1;
	cout<<bo1<<(bo1&&bo2)<<(bo1&&bo2&&bo3)<<(bo1&&bo2&&bo3&&bo4);
	return 0;
}
/*

*/ 
