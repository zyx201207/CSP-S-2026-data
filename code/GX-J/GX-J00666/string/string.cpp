#include <bits/stdc++.h>
using namespace std;
long long a[200000000];
string c[10000000];
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    set<string>st;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>c[i];
        st.insert(c[i]);
    }
    if(n==1)
    {

        cout<<0;
        return 0;
    }
    if(n==2)
    {

        if(c[1]==c[2])
        {
            cout<<0;
            return 0;
        }
        else
        {

            cout<<min(a[1],a[2]);
            return 0;
        }
    }
    if(st.size()==1)
    {
        cout<<0;

        return 0;

    }
    if(st.size()==2)
    {
        long long dy=0,dr=0;
        for(int i=1;i<=n/2;i++)
        {
            if(c[i]==c[1])
            {

                dy+=a[i];
            }
            else
            {
                dr+=a[i];
            }

        }
        cout<<dy;
        return 0;

    }
    string s="";
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<=a[i];i++)
        {
            s+=c[i];

        }
    }
    cout<<(s.size()-1)/2;

    return 0;
}
