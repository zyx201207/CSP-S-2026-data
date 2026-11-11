#include<iostream>
using namespace std;
int ans,a[10],p;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]!=c2[i])
        {
            p=1;
        }
    }
    if(p==0)
    {
        a[0]=1;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1] && p==0)
    {
        a[1]=1;
        if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))
        {
            a[2]=1;
            char b=s1[2],c=s2[2];
            if(abs(b-c)==1)
            {
                a[3]=1;
            }
        }
    }
    for(int i=0;i<=3;i++)
    {
        cout<<a[i];
    }
    return 0;
}
