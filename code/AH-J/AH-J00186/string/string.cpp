#include<bits/stdc++.h>
using namespace std;
int n,i,p1,p2;
char y;
long long s[200005][3],ans,a,x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        s[i][1]=x;
        s[i][2]=y-'a';
    }
    p1=1;p2=n;ans=0;
    while(p1<p2)
    {
        if(s[p1][2]==s[p2][2])
        {
            if(s[p1][1]>s[p2][1])
            {
                s[p1][1]-=s[p2][1];
                p2--;
            }
            else
            {
                if(s[p1][1]==s[p2][1])
                {
                    p1++;p2--;
                }
                else
                {
                    if(s[p1][1]<s[p2][1])
                    {
                        s[p2][1]-=s[p1][1];
                        p1++;
                    }
                }
            }
        }
        else
        {
            if(s[p1][1]>s[p2][1])
            {
                s[p1][1]-=s[p2][1];
                ans+=s[p2][1];
                p2--;
            }
            else
            {
                if(s[p1][1]==s[p2][1])
                {
                    ans+=s[p1][1];
                    p1++;p2--;
                }
                else
                {
                    if(s[p1][1]<s[p2][1])
                    {
                        s[p2][1]-=s[p1][1];
                        ans+=s[p1][1];
                        p1++;
                    }
                }
            }

        }
    }
    cout<<ans;
    return 0;
    fclose(stdout);
}
