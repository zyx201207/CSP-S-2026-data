#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout<<1;
    else cout<<0;
    if((s1[0] == s2[0])&&(s1[1] == s2[1])&&(c1 == c2)) cout <<1;
    else cout<<0;
    int a=0,b=0;
    if(s1[2]=='A') a=1;
    if(s1[2]=='B') a=2;
    if(s1[2]=='C') a=3;
    if(s1[2]=='D') a=100;
    if(s1[2]=='F') a=101;
    if(s2[2]=='A') b=1;
    if(s2[2]=='B') b=2;
    if(s2[2]=='C') b=3;
    if(s2[2]=='D') b=100;
    if(s2[2]=='F') b=101;
    int sum=abs(a - b);
    //cout<<"\n";
    //cout <<sum<<"\n";
    //cout <<a <<" " <<b<<"\n";

    if((s1[0] == s2[0])&&(s1[1] == s2[1])&&(c1 == c2)&&(sum < 3)) cout<< 1;
    else cout <<0;
    if((s1[0] == s2[0])&&(s1[1] == s2[1])&&(c1 == c2)&&(sum == 1)) cout<<1;
    else cout<<0;
    return 0;
}
