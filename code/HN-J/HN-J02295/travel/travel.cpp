#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,s1,c2,s2,a,b,c,d,f;
	cin>>c1>>s1>>c2>>s2;
	a='A';
	b='B';
	c='C';
	d='D'+1;
	f='F'+1;
	if(c1!=01&&c1!=16)
	cout<<1;
	else
	cout<<0;
	if(s1=s2+1)
	cout<<1;
	else
	cout<<0;
	if(c2!=01&&c2!=16)
	cout<<1;
	else
	cout<<0;
	if(s2=s1-1)
	cout<<1;
	else
	cout<<0;
	return 0;
}
