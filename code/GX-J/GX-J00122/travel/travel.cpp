#include <bits/stdc++.h>
using namespace std;
int ly(int c1,int c2,string s1,string s2,int i)
{
    string s3="",s4="";
    for(int j=0;j<2;j++)
    {
        s3+=s1[j];
        s4+=s2[j];
    }
    switch (i)
    {
        case 1:
            return c1==c2;
        case 2:
            return s3==s4;
        case 3:
            if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')) return 1;
            else return 0;
        case 4:
            if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) return 1;
            else return 0;

    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2,s="";
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=4;i++)
    {
        if(ly(c1,c2,s1,s2,i)) s+="1";
        else
        {
            for(int j=i;j<=4;j++) s+="0";
            cout<<s;
            return 0;
        }
    }
    cout<<s;
    return 0;
}

