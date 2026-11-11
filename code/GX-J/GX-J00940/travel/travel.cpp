#include<bits/stdc++.h>
using namespace std;
long long a,b;
string x,y;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    if(a==b){cout<<1;}
    else {cout<<0<<0<<0<<0;return 0;}

    string c=x.substr(1,1),d=y.substr(1,1);

    if(c==d) {cout<<1;}
    else {cout<<0<<0<<0;return 0;}

    string e=x.substr(2,1),f=y.substr(2,1);

    if((e>="A"&&e<="C"&&f>="A"&&f<="C")||((e=="D"||e=="F")&&(f=="D"||f=="F"))){cout<<1;}
    else {cout<<0<<0;return 0;}

    if((e=="A"&&f=="B")||(e=="B"&&f=="C")||(e=="D"&&f=="F")) {cout<<1;}
    else {cout<<0;return 0;}

    return 0;
}
