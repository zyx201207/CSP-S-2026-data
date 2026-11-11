#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<char> c(n+1);
    unsigned long long zongshu=0,ans=0;
    bool quandeng=true;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        zongshu+=a[i];
    }
    vector<char> s(zongshu-1);
    long long dangqian=0;
    for(int r=0;r<n;r++)
    {
        for(int x=0;x<a[r];x++)
        {
            s[dangqian]=char(c[r]);
            dangqian++;

        }
    }
    if(zongshu%2==1)
    {
        for(int q=1;q<=zongshu/2;q++)
        {
            if(s[zongshu/2-q]!=s[zongshu/2+q])
            {
                ans++;
            }

        }

    }
    else if(zongshu%2==0)
    {
        for(int w=1;w<=zongshu/2-1;w++)
        {
            if(s[zongshu/2-w-1]!=s[zongshu/2+w])
            {
                ans++;
            }
        }

    }
    cout<<ans;
    return 0;
}

