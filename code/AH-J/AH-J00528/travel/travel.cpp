#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int row1,row2;
char code1,code2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c_1>>s_1>>c_2>>s_2;
    row1=(s_1[0]-'0')*10+(s_1[1]-'0');
    row2=(s_2[0]-'0')*10+(s_2[1]-'0');
    code1=s_1[2];
    code2=s_2[2];
    if(code1>code2)
        swap(code1,code2);
    if(c_1==c_2)
        cout<<1;
    else
        cout<<0;
    if(c_1==c_2&&row1==row2)
        cout<<1;
    else
        cout<<0;
    if(c_1==c_2&&row1==row2&&((code1=='A'&&code2=='B')||(code1=='C'&&code2=='D')||(code1=='C'&&code2=='E')||(code1=='D'&&code2=='E')) )
        cout<<1;
    else
        cout<<0;
    if(c_1==c_2&&row1==row2&&((code1=='A'&&code2=='B')||(code1=='C'&&code2=='D')||(code1=='D'&&code2=='E')))
        cout<<1;
    else
        cout<<0;
    return 0;
}
