#include<bits/stdc++.h>
#define ll long long;
#define ull unsigned long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int t1,t2,t3,r1,r2,r3;
    bool b1,b2,b3,b4;
    cin>>c1>>s1>>c2>>s2;
    t1=(c1[0]-'0')*10+c1[1]-'0';
    t2=(s1[0]-'0')*10+s1[1]-'0';
    t3=(s1[2]-'A');
    r1=(c2[0]-'0')*10+c2[1]-'0';
    r2=(s2[0]-'0')*10+s2[1]-'0';
    r3=(s2[2]-'A');
    b1=(t1==r1);
    b2=b1&&(t2==r2);
    b3=b2&&((t3<3&&r3<3)||(t3>2&&r3>2));
    b4=b3&&(abs(r3-t3)==1);
    cout<<b1<<b2<<b3<<b4;
    return 0;
}
