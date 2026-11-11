#include <bits/stdc++.h>
using namespace std;

long long a[200010];
long long sa[5];
char c[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        //sa[i]=sa[i-1]+a[i];
        cin >> c[i];
        cnt+=a[i];
    }
    sa[2]=cnt;
    //int flag=0;
    /*
    for(int i=1;i<=n;i++)
    {
        if(sa[i]>cnt/2) flag=i;
    }*/
    long long sum=0;
    //cout << "cnt:" << cnt <<endl;
    //if(cnt%2==0)
    //{
        int i=1,j=n;
        while(sa[1]<=cnt/2&&sa[2]>cnt/2)
        {
            if(a[i]>a[j])
            {
                if(c[i]!=c[j]) sum+=a[j];
                a[i]-=a[j];
                sa[1]+=a[j];
                sa[2]-=a[j];
                j--;
            }
            else if(a[i]<a[j])
            {
                if(c[i]!=c[j]) sum+=a[i];
                a[j]-=a[i];
                sa[1]+=a[i];
                sa[2]-=a[i];
                i++;
            }
            else
            {
                if(c[i]!=c[j]) sum+=a[i];
                sa[1]+=a[i];
                sa[2]-=a[j];
                i++;
                j--;
            }
            //cout << sum << "!" <<endl;
        }
        //if(sa[1]>cnt/2)

    //}
    cout << sum << endl;
    return 0;
}
