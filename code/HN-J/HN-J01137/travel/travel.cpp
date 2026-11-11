#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool pd(char a,char b)
{
	if(a=='A' || a=='B' || a=='C')
	{
		if(b=='A' || b=='B' || b=='C')
		{
			return true;
		}else{
			return false;
		}
	}else{
		if(a=='D' || a=='F')
		{
			if(b=='D' || b=='F')
			{
				return true;
			}
		}else{
			return false;
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]-'0'==s2[0]-'0' && s1[1]-'0'==s2[1]-'0')
		{
			cout<<1;
			if(pd(s1[2],s2[2]))
			{
				cout<<1;
				if(s1[2]-'0'+1==s2[2]-'0' || s2[2]-'0'+1==s1[2]-'0')
				{
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
