#include <bits/stdc++.h>

using namespace std;


int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    int sl1,sl2,sp1,sp2;
    cin>>c1>>s1>>c2>>s2;
    sl1 = (s1[0]-'0')*10+s1[1]-'0';
    sp1 = s1[2]-'A'+1;
    sl2 = (s2[0]-'0')*10+s2[1]-'0';
    sp2 = s2[2]-'A'+1;
    if(c1==c2)cout<<"1";
    else cout<<"0";
    if(c1==c2&&sl1==sl2)cout<<"1";
    else cout<<"0";
    if(c1==c2&&sl1==sl2&&((sp1>=1&&sp1<=3&&sp2>=1&&sp2<=3)||(sp1>=4&&sp1<=5&&sp2>=4&&sp2<=5)))cout<<"1";
    else cout<<"0";
    if(c1==c2&&sl1==sl2&&((sp1>=1&&sp1<=3&&sp2>=1&&sp2<=3)||(sp1>=4&&sp1<=5&&sp2>=4&&sp2<=5))&&(sp1-sp2==1||sp2-sp1==1))cout<<"1";
    else cout<<"0";
    return 0;
}
