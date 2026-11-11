#include<bits/stdc++.h>
using namespace std;
int C,c;
string S,s;
bool fr()
{
//	cout<<"a";
	if(C==c)//1
	{
		cout<<1;
		return 1;
	}else{
		cout<<0;
		return 0;
	}
	
}
bool se()
{
//	cout<<"b";
		int P = S[0]-'0'*10+S[1]-'0';
		int p = s[0]-'0'*10+s[1]-'0';
		if(P==p)//2
		{
			cout<<1;
			return 1;
		}else{
			cout<<0;
			return 0;
		}
}
bool tr()
{
	//cout<<"c";
	int Q = S[2]-'0';
	int q = s[2]-'0';
	if(Q>=20&&q>=20)
	{
		cout<<1;
		return 1;
	}else if(Q<=19&&q<=19)
	{
		cout<<1;
		return 1;
	}
	return 0;
}
bool fo()
{
	//cout<<"d";
	int Q = S[2]-'0';
	int q = s[2]-'0';
	if(max(Q,q)-min(Q,q)==1)
	{
		if(Q==19&&q==20)
		{
			cout<<0;
		}else if(Q==19&&q==20)
		{
			cout<<0;
		}else{
			cout<<1;
			return 1;
		}
	}else{
		cout<<0;
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C>>S;
	cin>>c>>s;
	int on = fr();
	if(on==1)
	{
		int t = se();
		if(t==1)
		{
			int th = tr();
			if(th==1)
			{
				fo();
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
	}

 } 
