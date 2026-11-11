#include<bits/stdc++>
using namespace std;
int n,a[2000000],b[2000000];
map<int,int> mp;
map<int,int> mp2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(mp.count(a[j]))
            {
                for(int x=mp2[a[j]];x<j;x++)
                {
                    mp2[a[x]]=0;
                }
            }
            else
            {
                mp2[a[j]]=j;
                mp[j]=a[j];
            }
        }
        for(int j=1;j<=n;j++)
        {
            mp[j]=0;
            if(mp2[a[j]]>0)
            {
                b[a[j]]++;
                mp2[a[j]]=0;
            }
        }
    }
    for(int i=1;i<=2000000;i++)
    {
        if(b[a[j]]>0)
        {
            cout<<b[a[j]];
        }
    }
    return 0;
}
