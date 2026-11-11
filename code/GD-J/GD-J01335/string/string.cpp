#include <iostream>

using namespace std;

int n;
long long a[200005];
char c[200005];
long long s[200005];
long long ans;
//int num;
bool check()
{
    bool flag=true;
    for(int i=1;i<=n/2;i++)
    {
        int m=n+1-i;
        if(a[i]!=a[m]||c[i]!=c[m])
        {
            flag=false;
            break;
        }
    }
    return 0;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1])
        {
            a[i-1]+=a[i];
            i--;
            n--;
        }
        if(c[i]!=c[i-1])
        {
            flag=false;
        }

    }
    if(flag)
    {
        cout<<0;
        return 0;
    }
    if(check())
    {
        cout<<0;
        return 0;
    }
    int j=n;
    for(int i=1;i<=n;i++)
    {
        long long s1=a[i];
        //num+=a[i];
        long long s2=0;
        long long na=0;
        for(;j>i;j--)
        {

            int b=s2+a[j];
            //cout<<b<<' '<<s2<<' '<<a[j]<<endl;
            if(b>=s1)
            {
                if(c[j]!=c[i])
                    na+=s1-s2;
                s2+=a[j];
                a[j]=s2-s1;
                break;
            }
            s2+=a[j];
            //cout<<s2<<' '<<"nihfa"<<endl;
            if(c[i]!=c[j])
            {
                na+=a[j];
            }
        }
        //cout<<j<<' '<<na<<endl;
        ans+=na;
    }
    cout<<ans;
    return 0;
}

