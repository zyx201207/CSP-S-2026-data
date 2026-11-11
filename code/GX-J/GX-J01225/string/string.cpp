#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
string s;
bool re_place(string x)
{
    string y;
    for(int i=x.size()-1;i>=0;i--)y+=x[i];
    if(y==x)return true;
    return false;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    if(re_place(s)==true)
    {
        cout<<0;
        return 0;
    }
    else
    {
        int t=(s.size()+1)/2-1;
        string x=s.substr(0,t-1),y=s,substr(t+1,s.size()-1);
        for(int i=1;i<=t;i++)
        {
            if(y[i]!=x[i])
            {
                y[i]=x[i];
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
