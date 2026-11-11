#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
unsigned long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<j)
    {
        if(a[i]>a[j])
        {
            if(c[i]==c[j])
            {
                a[i]-=a[j];
                j--;
            }
            else
            {
                a[i]-=a[j];
                ans+=a[j];
                j--;
            }
        }

        if(a[i]<a[j])
        {
            if(c[i]==c[j])
            {
                a[j]-=a[i];
                i++;
            }
            else
            {
                a[j]-=a[i];
                ans+=a[i];
                i++;
            }
        }

        if(a[i]==a[j])
        {
            if(c[i]==c[j])
            {
                i++;
                j--;
            }
            else
            {
                ans+=a[i];
                i++;
                j--;
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}