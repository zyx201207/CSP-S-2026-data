#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool ok1=true,ok2=true,ok3=true,ok4=true;
    if(c1==c2&&c1!="01"&&c1!="16") ok1=true;
    else ok1=false;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            if(s1[i]!=s2[i]||ok1==false)
            {
                ok2=false;
            }
        }
        else
        {
            if(s1[i]>='A'&&s2[i]<='C')
            {
                if(s2[i]>='A'&&s2[i]<='C'&&s2[i]!=s1[i]&&ok1&&ok2) ok3=true;
                else ok3=false;
            }
            else{
                if(s1[i]!=s2[i]&&s1[i]>='D'&&s1[i]<='F'&&ok1&&ok2) ok3=true;
                else ok3=false;
            }
        }
    }
    int len1=s1.size(),len2=s2.size();
    int p=abs(s1[len1-1]-s2[len2-1]);
    if(ok1&&ok2&&ok3&&p==1) ok4=true;
    else ok4=false;
    cout<<int(ok1)<<int(ok2)<<int(ok3)<<int(ok4);
    return 0;
}