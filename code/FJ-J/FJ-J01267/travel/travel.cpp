#include<bits/stdc++.h>
using namespace std;

bool check(char a,char b)
{
	char aa=a,bb=b;
	if(aa>bb) swap(aa,bb); 
	if(aa=='C') return false;
	if(aa=='D'&&bb=='F') return true;
	if(bb-aa==1) return true;
	else return false;
}

bool check2(char a,char b)
{
	if(a<='C'&&b>'C') return false;
	else return true;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1.substr(0,2)!=s2.substr(0,2))
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!check2(s1[2],s2[2]))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(check(s1[2],s2[2])) cout<<1;
	else cout<<0;
	return 0;
} 
