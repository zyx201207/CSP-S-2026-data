#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string s3=s1.substr(0,2),s4=s2.substr(0,2);
    cout<<(c1==c2 ? 1 :0);
    cout<<(c1==c2&&s3==s4 ? 1 :0);
    cout<<(c1==c2&&s3==s4&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) ? 1 :0);
    cout<<(c1==c2&&s3==s4&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&abs(s1[2]-s2[2])==1? 1 :0);
    return 0;
}

