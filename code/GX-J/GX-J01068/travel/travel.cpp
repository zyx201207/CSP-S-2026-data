#include<bits/stdc++.h>
using namespace std;
string s,z,n,m;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int i,j,I,J;
    cin>>n>>s>>m>>z;
    if(n[0]==m[0] && n[1]==m[1])
    {
        cout<<"1";
        i=s[0]-'0';
        j=s[1]-'0';
        I=z[0]-'0';
        J=z[1]-'0';
        if(i==I && j==J)
        {
			cout<<"1";
			if((s[2]<='C' && z[2]<='C') || (s[2]>='D' && z[2]>='D'))
			{
				cout<<"1";
				if(s[2]+1==z[2] || s[2]-1==z[2])
				{
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
	    }else{
			cout<<"000";
		}
    }else{
        cout<<"0000";
    }
	return 0;
}
