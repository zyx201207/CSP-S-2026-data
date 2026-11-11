#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int da[200005];
char dc[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    /*string s="";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    string s1="";
    for(int i=s.size()-1;i>=0;i--)
    {
        s1+=s[i];
    }
    int sum=0;
    for(int i=0;i<(s.size()+1)/2;i++)
    {
        if(s1[i]!=s[i])
        {
            sum++;
        }
    }
    cout<<sum<<endl;*/
    for(int i=n;i>=1;i--)
    {
        da[n-i+1]=a[i];
        dc[n-i+1]=c[i];
    }
    int x=a[1],x1=da[1];
    long long sum=0;
    char y=c[1],y1=dc[1];
    for(int i=1;i<=(n+1)/2;i++)
    {
        if(y==y1)
        {
            if(x>x1)
            {
                x-=x1;
                x1=0;
                x1=da[i+1];
                y1=dc[i+1];
                //cout<<1<<endl;
            }
            else
            {
                x1-=x;
                x=0;
                x=a[i+1];
                y=c[i+1];
                if(x1==0)
                {
                    x1=da[i+1];
                    y1=dc[i+1];
                }
                //cout<<2<<endl;
            }
        }
        else if(y!=y1)
        {
            if(x>x1)
            {
                sum+=x1;
                x-=x1;
                x1=0;
                x1=da[i+1];
                y1=dc[i+1];
                //cout<<3<<endl;
            }
            else
            {
                sum+=x;
                x1-=x;
                x=0;
                x=a[i+1];
                y=c[i+1];
                if(x1==0)
                {
                    x1=da[i+1];
                    y1=dc[i+1];
                }
                //cout<<4<<endl;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
