#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2,s1,s2,sf,se;
char x,cx,cr;
bool pd;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>c1;
    if(x=='1')c1+=10;
    cin>>x>>s1;
    cin>>cr;
    if(x=='1')s1+=10;
    sf=cr-'A'+1;
    cin>>x>>c2;
    if(x=='1')c2+=10;
    cin>>x>>s2;
    cin>>cx;
    if(x=='1')s2+=10;
    se=cx-'A'+1;
    
    pd=true;
    
    if(c1==c2)cout<<1;
    else {cout<<0;pd=false;}
    
    if(s1==s2&&pd==true)cout<<1;
    else {cout<<0;pd=false;}
    
    if(sf>=4&&se>=4&&pd==true)cout<<1;
    else if(sf<=3&&se<=3&&pd==true)cout<<1;
    else {cout<<0;pd=false;}
    
    if((sf-se==1||se-sf==1)&&pd==true)cout<<1;
    else if(se==4&&sf==6&&pd==true)cout<<1;
    else if(se==6&&sf==4&&pd==true)cout<<1;
    else cout<<0;
    
    return 0;
}
//100
