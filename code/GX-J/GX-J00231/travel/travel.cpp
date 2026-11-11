#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char sc1,sc2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>sc1>>c2>>s2>>sc2;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2&&s1==s2)cout<<1;
    else cout<<0;
    if(c1==c2&&s1==s2&&((sc1=='A'&&sc2=='B')||(sc1=='A'&&sc2=='C')||(sc1=='B'&&sc2=='C')||(sc1=='D'&&sc2=='F')||(sc1=='B'&&sc2=='A')||(sc1=='C'&&sc2=='A')||(sc1=='C'&&sc2=='B')||(sc1=='F'&&sc2=='D')))cout<<1;
    else cout<<0;
    if(c1==c2&&s1==s2&&((sc1=='A'&&sc2=='B')||(sc1=='B'&&sc2=='C')||(sc1=='D'&&sc2=='F')||(sc1=='B'&&sc2=='A')||(sc1=='C'&&sc2=='B')||(sc1=='F'&&sc2=='D')))cout<<1;
    else cout<<0;
    return 0;
}
