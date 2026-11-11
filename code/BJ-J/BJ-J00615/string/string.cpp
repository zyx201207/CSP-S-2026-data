#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],s[200005][2],ans,t;
char ch[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>ch[i];
        s[i][0]=s[i-1][0]+a[i];
    }
    for(int i=n;i>=1;i--)
    {
        s[i][1]=s[i+1][1]+a[i];
    }
    t=s[n][0]/2;
    for(int i=1,j=n;i<=n&&j>=1;)
    {
        if(i>j)break;
        if(s[i][0]>=t&&s[j][1]>=t)
        {
            if(ch[i]!=ch[j]) ans+=min(t-s[i-1][0],t-s[j+1][1]);
            break;
        }
        else if(s[i][0]<s[j][1])
        {
            if(ch[i]!=ch[j])
            {
                ans+=s[i][0]-max(s[i-1][0],s[j+1][1]);
            }
            i++;
        }
        else if(s[i][0]==s[j][1])
        {
            if(ch[i]!=ch[j])ans+=min(s[i][0]-s[i-1][0],s[j][1]-s[j+1][1]);
            i++,j--;
        }
        else
        {
            if(ch[i]!=ch[j])
            {
                ans+=s[j][1]-max(s[i-1][0],s[j+1][1]);
            }
            j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
