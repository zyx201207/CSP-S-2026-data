#include<bits/stdc++.h>
using namespace std;
int c1,c2,c3,c4;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>c2>>s1>>c3>>c4>>s2;
	if(c1==c3)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(c2==c4)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C'))||((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')))
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if((s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')||(s1=='B'&&s2=='C')||(s1=='C'&&s2=='B')||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D'))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
