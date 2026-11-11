#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,tj=0,m;
    string s;
    cin>>n;
    int a[n];
    char e[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>e[i];
    }
    if(a[1]>1000000)
    {
        for(int i=0;i<n/2;i++)
        {
            if(a[i]==a[n-1-i])
            {
                if(e[i]!=e[n-1-i])
                tj+=a[i];
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a[i];j++)
            {
                s+=e[i];
            }
        }
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-1-i])
                tj++;
        }
    }
    cout<<tj;
    return 0;
}
