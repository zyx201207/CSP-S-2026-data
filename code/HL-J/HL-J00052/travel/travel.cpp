#include<bits/stdc++.h>
using namespace std;
long long n,nq,np,npq;
char z,zq;
string s,sq;
bool x=0,p=0,c=0,l=0;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>n>>s>>nq>>sq;
    x=(n==nq);
    np=(s[0]-'0')*10+(s[1]-'0');
    npq=(sq[0]-'0')*10+(sq[1]-'0');
    z=s[2];
    zq=sq[2];
    p=(x&&(np==npq));
    c=((x&&(p&&((z<='C'&&z>='A')&&(zq<='C'&&zq>='A'))||((z<='F'&&z>='D')&&(zq<='F'&&zq>='D')))));
    l=(x&&(p&&(c&&((z+1==zq)||(zq+1==z)))));
    cout<<x<<p<<c<<l;
    return 0;
}
