#include <bits/stdc++.h>

using namespace std;

long long a[2000005];
char b[2000005];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int num=1;
    int num2=n;
    long long ans=0;
    while(num!=num2)
    {
        if(b[num]!=b[num2])
        {
            if(a[num]>a[num2])
            {
                ans+=a[num2];
                a[num]-=a[num2];
                num2--;
            }
            else if(a[num]<a[num2])
            {
                ans+=a[num];
                a[num2]-=a[num];
                num++;
            }
            else
            {
                ans+=a[num];
                num++;
                num2--;
            }
        }
        else
        {
            if(a[num]>a[num2])
            {
                a[num]-=a[num2];
                num2--;
            }
            else if(a[num]<a[num2])
            {
                a[num2]-=a[num];
                num++;
            }
            else
            {
                num++;
                num2--;
            }
        }
    }
    cout<<ans;
    return 0;
}
