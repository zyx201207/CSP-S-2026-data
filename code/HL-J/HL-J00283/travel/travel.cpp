#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b;
    string m,n;
    int a1,b1;
    cin>>a>>m>>b>>n;
    if(a==b)//chexiang
    {
        cout<<'1';
        if(m[0]==n[0]&&m[1]==n[1])//pai 
        {
            cout<<1;
            if( ( (m[2]=='A'||m[2]=='B'||m[2]=='C')&&(n[2]=='A'||n[2]=='B'||n[2]=='C') ) ||(((m[2]=='D')||(m[2]=='F'))&&((n[2]=='D')||(n[2]=='F'))) )//ce
            {
            	cout<<1;
            	if(m[2]=='A'&&n[2]=='B') cout<<1;
            	else if(m[2]=='B'&&(n[2]=='A'||n[2]=='B') ) cout<<1;
            	else if(m[2]=='C'&&n[2]=='B') cout<<1;
            	else if(m[2]=='D'&&n[2]=='F') cout<<1;
            	else if(m[2]=='F'&&n[2]=='D') cout<<1;
            	else cout<<0;
			}
			else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}


