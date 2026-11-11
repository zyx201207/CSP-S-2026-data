#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    string qwe=s2.substr(0,2);
    string wer=s4.substr(0,2);
    if(s1==s3&&qwe==wer)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    char asd=s2[2];
    char sdf=s4[2];
    if(s1==s3&&qwe==wer&&((asd>='A'&&asd<='C'&&sdf>='A'&&sdf<='C')||(asd=='D'&&sdf=='F')||(asd=='F'&&sdf=='D')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1==s3&&qwe==wer&&asd>='A'&&asd<='C'&&sdf>='A'&&sdf<='C')
    {
        if((asd=='A'&&sdf=='B')||(asd=='A'&&sdf=='C')||(asd=='B'&&sdf=='C'))
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    if(s1==s3&&qwe==wer&&((asd=='D'&&sdf=='F')||(asd=='F'&&sdf=='D')))
    {
        cout<<1;
        return 0;
    }
    else
    {
        cout<<0;
        return 0;
    }
}
