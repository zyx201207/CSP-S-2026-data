#include<bits/stdc++.h>
using namespace std;
int main()
{
        freopen("card.in","r",stdin);
        freopen("card.out","w",stdout);
        int n,a[500005],m;
        int cc[300005],r[300005];
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int k=0;k<n;k++)
        {
            string s;
            for(int i=k;i<n;i++)
            {
                if(s.find(a[i])!=string::npos)s.erase(s.find(a[i]));
                s+=a[i];
            }
            int len=s.size();
            for(int i=0;i<len;i++)
            {
                int w=s[i]-'0';
                cc[w]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!r[i])
            {
                cout<<cc[i]<<" ";
                r[i]=1;
            }
        }
        return 0;
}
