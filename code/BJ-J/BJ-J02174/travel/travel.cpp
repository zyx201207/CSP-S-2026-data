#include <bits/stdc++.h>
using namespace std;
#define ll long long
char a,b,c;
int x,y,z,w,X,Y,Z,W;
int calc(char a,char b)
{
    return (a-'0')*10+(b-'0');
}
int calc2(char c)
{
    if(c=='A') return 1;
    if(c=='B') return 2;
    if(c=='C') return 3;
    if(c=='D') return 4;
    if(c=='F') return 5;
}
int calc3(int c)
{
    if('A'<=c&&c<='C') return 1;
    return 2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>a>>b;
    x=calc(a,b);
    cin>>a>>b>>c;
    y=calc(a,b);
    z=calc2(c);
    w=calc3(c);
    cin>>a>>b;
    X=calc(a,b);
    cin>>a>>b>>c;
    Y=calc(a,b);
    Z=calc2(c);
    W=calc3(c);
    cout<<(x==X)<<(x==X&&y==Y)<<(x==X&&y==Y&&w==W)<<(x==X&&y==Y&&w==W&&abs(z-Z)==1);
    return 0;
}