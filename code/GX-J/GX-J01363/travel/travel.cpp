#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>c1>>s1>>c2>>s2;
    int ans1=0,ans2=0,ans3=0,ans4=0,a=0,b=0;
    if(c1==c2)
    {
        ans1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            ans2=1;
            if(s1[2]<='C') a=1;
            if(s2[2]<='C') b=1;
            if(a&&b||a==0&&b==0)
            {
                    ans3=1;
                    if(abs(s1[2]-s2[2])==1)
                        ans4=1;
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
