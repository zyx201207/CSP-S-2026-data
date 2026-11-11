#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s11,s22;
char c11,c22;
bool b1=0,b2=0,b3=0,b4=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        s11+=s1[i];
        s22+=s2[i];
    }
    c11=s1[2];
    c22=s2[2];
    if(c1==c2)
    {
        b1=1;
    }//same chexiang
    if(b1==1&&s11==s22){
        b2=1;
    }//same pai
    if(b2==1){
        if((c11>='A'&&c11<='C')&&(c22>='A'&&c22<='C'))
        {
            b3=1;
        }
        else if((c11>='D'&&c11<='F')&&(c22>='D'&&c22<='F'))
        {
            b3=1;
        }
    }//same ce
    if(b3==1){
        int a=int(c11-c22);
        if(abs(a)==1) b4=1;
    }
    cout<<b1<<b2<<b3<<b4;
    return 0;
}
