#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    int r1=stoi(s1.substr(0,2));
    int r2=stoi(s2.substr(0,2));
    char col1=s1[2];
    char col2=s2[2];

    bool b1=(c1==c2);
    bool b2=(r1==r2);
    bool b3;
    if(col1=='A'||col1=='B'||col1=='C') b3=(col2=='A'||col2=='B'||col2=='C');
    if(col1=='D'||col1=='F') b3=(col2=='D'||col2=='F');
    bool b4=(col1==(col2+1)||col2==(col1+1));
    cout<<(b1);
    cout<<(b1&&b2);
    cout<<(b1&&b2&&b3);
    cout<<(b1&&b2&&b3&&b4);
    return 0;
}