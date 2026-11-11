#include<iostream>
#include<cstdio>
using namespace std;
int a1,a2,b1,b2,a,b;
char a3,b3;
bool ans1,ans2,ans3,ans4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    a=a3-'A'+1;
    b=b3-'A'+1;
    if(a1==b1)
    {
        ans1=1;
        if(a2==b2)
        {
            ans2=1;
            if((a==4&&b==6)||(a==6&&b==4)||(a!=4&&a!=6&&b!=4&&b!=6))
            {
                ans3=1;
                if((a==4&&b==6)||(a==6&&b==4)||(a==1&&b==2)||(a==2&&b==1)||(a==2&&b==3)||(a==3&&b==2))
                {
                    ans4=1;
                }
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
