#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int ans[5],p1,p2;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
        ans[1]=1;
    for(int i=0;i<=1;i++)
        p1=p1*10+s2[i],p2=p2*10+s4[i];
    if(p1==p2&&ans[1]==1)
        ans[2]=1;
    p1=s2[2];
    p2=s4[2];
    if(ans[2]==1)
    {

        if(p1=='D'||p2=='D')
        {
            if(p1=='D'&&p2=='F')
                ans[3]=1;
            else
            {
                if(p1=='F'&&p2=='D')
                    ans[3]=1;
            }
        }
        else
        {

            if(abs(p1-p2)==1||abs(p1-p2)==2)
                ans[3]=1;
            if(abs(p1-p2)==1)
                ans[4]=1;
        }
    }
    for(int i=1;i<=4;i++)
        cout<<ans[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
