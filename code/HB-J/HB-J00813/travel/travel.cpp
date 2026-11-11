#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    string p1,p2;
    char w1,w2;
    p1=s1.substr(0,2);
    p2=s2.substr(0,2);
    w1=s1[2];
    w2=s2[2];
    bool b1=(c1==c2),b2=(p1==p2),b3=(((w1>='A')&&(w1<='C')&&(w2>='A')&&(w2<='C'))||((w1>='D')&&(w1<='F')&&(w2>='D')&&(w2<='F')));
    if ((int)w1>(int)w2)
    {
        swap(w1,w2);
    }
    bool b4=(((w1=='A')&&(w2=='B'))||((w1=='B')&&(w2=='C'))||((w1=='D')&&(w2=='F')));
    cout<<(b1)<<(b1&&b2)<<(b1&&b2&&b3)<<(b1&&b2&&b3&&b4);
    return 0;
}