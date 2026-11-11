#include<bits/stdc++.h>
using namespace std;
string c,z,cc,zz;
bool check()
{
    if(z[2]=='F'||z[2]=='D')
        return (zz[2]=='F'||zz[2]=='D');
    if(z[2]=='A'||z[2]=='B'||z[2]=='C')
        return (zz[2]=='A'||zz[2]=='B'||zz[2]=='C');
}
bool l()
{
    if(z[2]=='F'&&zz[2]=='D')return 1;
    if(z[2]=='D'&&zz[2]=='F')return 1;
    if(z[2]=='A'&&zz[2]=='B')return 1;
    if(z[2]=='B'&&zz[2]=='A')return 1;
    if(z[2]=='B'&&zz[2]=='C')return 1;
    if(z[2]=='C'&&zz[2]=='B')return 1;

    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>z>>cc>>zz;
    if(c==cc)cout<<1;
    else cout<<0;
    if(c==cc&&z[0]==zz[0]&&z[1]==zz[1])cout<<1;
    else cout<<0;
    if(c==cc&&z[0]==zz[0]&&z[1]==zz[1]&&check())cout<<1;
    else cout<<0;
    if (c==cc&&z[0]==zz[0]&&z[1]==zz[1]&&check()&&l())cout<<1;
    else cout<<0;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
