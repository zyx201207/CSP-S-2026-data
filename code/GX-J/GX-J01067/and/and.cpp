#include <bits/stdc++.h>

using namespace std;

string t(string s1,string s2)
{
        for(int i=0;i<max(s1.size(),s2.size());i++)
        {
            if(s1[i]=='1'&&s2[i]==s1[i])
                s1[i]='1';
            else
                s1.erase(i,1);
        }
        return s1;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,zd=0,h=0;
    string s1,s2;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n-m;i++)
    {
        s1.erase(0,s1.size());
        s2.erase(0,s2.size());
        int k=a[i];
        while(k)
        {
            s1+=k%2+'0';
            k/=2;
        }
        for(int j=i+1;j<n;j++)
        {

            for(int o=0;o<m-1;o++)
            {
                s2.erase(0,s2.size());
                int l=a[j+o];
                while(l)
                {
                    s2+=l%2+'0';
                    l/=2;
                }
                s1=t(s1,s2);
            }
            for(int i=0;i<s1.size();i++)
            {
                int w=1;
                if(s1[i]=='1')
                {
                    for(int j=i;j>0;j--)
                    {
                        w*=2;
                    }
                    h+=w;
                }
                zd=max(h,zd);
            }
            h=0;
        }
    }
    cout<<zd;
    return 0;
}
