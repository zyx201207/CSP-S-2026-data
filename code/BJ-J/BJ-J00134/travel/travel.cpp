#include<bits/stdc++.h>
using namespace std;
//          A B C D E F
int mp[26]={1,2,3,4,0,5};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int ca,cb,sa,sb;
    char a,b;
    cin>>ca>>sa>>a>>cb>>sb>>b;
    bool f[4];
    f[0]=(ca==cb);
    f[1]=(sa==sb);
    f[2]=((a<='C'&&b<='C')||(a>='D'&&b>='D'));
    f[3]=(abs(mp[a-'A']-mp[b-'A'])==1);
    cout<<(f[0]);
    cout<<(f[0]&&f[1]);
    cout<<(f[0]&&f[1]&&f[2]);
    cout<<(f[0]&&f[1]&&f[2]&&f[3]);
    return 0;
}