#include<iostream>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int n;
int sum;
int chuana[N];
char chuanc[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i]>>c[i];
        sum+=a[i];
    }
    int len=sum/2;
    if(sum%2==1)
    {
        len++;
    }
    int s=0;
    int cnt=0;
    int pos=1;
    while(s<len)
    {
        if(s+a[pos]<=len)
        {
            s+=a[pos];
            chuana[++cnt]=a[pos];
            chuanc[cnt]=c[pos];
            pos++;
        }
        else
        {
            chuana[++cnt]=len-s;
            a[pos]-=chuana[cnt];
            chuanc[cnt]=c[pos];
            s=len;
        }
    }
    if(sum%2==1)
    {
        if(chuana[cnt]==1)
        {
            cnt--;
        }
        else
        {
            chuana[cnt]--;
        }
        int j=pos;
        int res=0;
        for(int i=cnt;i>=1;)
        {
            if(chuana[i]==a[j])
            {
                if(chuanc[i]==c[j])
                {
                }
                else
                {
                    res+=a[j];
                }
                i--,j++;
            }
            else if(chuana[i]<a[j])
            {
                a[j]-=chuana[i];
                if(chuanc[i]==c[j])
                {
                }
                else
                {
                    res+=chuana[i];
                }
                i--;
            }
            else if(chuana[i]>a[j])
            {
                chuana[i]-=a[j];
                if(chuanc[i]==c[j])
                {
                }
                else
                {
                    res+=a[j];
                }
                j++;
            }
        }
        cout <<res;
    }
    if(sum%2==0)
    {
        int j=pos;
        int res=0;
        for(int i=cnt;i>=1;)
        {
            if(chuana[i]==a[j])
            {
                if(chuanc[i]==c[j])
                {
                }
                else
                {
                    res+=a[j];
                }
                i--,j++;
            }
            else if(chuana[i]<a[j])
            {
                a[j]-=chuana[i];
                if(chuanc[i]==c[j])
                {
                }
                else
                {
                    res+=chuana[i];
                }
                i--;
            }
            else if(chuana[i]>a[j])
            {
                chuana[i]-=a[j];
                if(chuanc[i]==c[j])
                {
                }
                else
                {
                    res+=a[j];
                }
                j++;
            }
        }
        cout <<res;
    }
    return 0;
}
