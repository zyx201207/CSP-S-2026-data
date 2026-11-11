//GZ-J00077 中央民族大学附属中学贵阳学校 李思润
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1])
    {
        cout<<0<<0<<0<<0<<endl;
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<1000<<endl;
        return 0;
    }
    if((s1[2]=='D'&&s2[2]!='F')||(s1[2]!='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]!='D')||(s1[2]!='F'&&s2[2]=='D'))
    {
        cout<<1100<<endl;
        return 0;
    }
    if(s1[2]-'A'==s2[2]-'A'+1||s1[2]-'A'==s2[2]-'A'-1)cout<<1111<<endl;
    else cout<<1110<<endl;

    return 0;
}
