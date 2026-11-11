#include<iostream>
using namespace std;
long long n,a[100005],head=1,tail,ans=0;
char a1[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>a1[i];
    }
    tail=n;
    while(tail>head)
    {
        if(a1[head]==a1[tail])
        {
            if(a[head]>a[tail])
            {
                a[head]-=a[tail];
                tail--;
            }
            else if(a[head]<a[tail])
            {
                a[tail]-a[head];
                head++;
            }
            else{
                tail--;
                head++;
            }
        }
        else
        {
            if(a[head]>a[tail])
            {
                ans+=a[tail];
                a[head]-=a[tail];
                tail--;
            }
            else if(a[head]<a[tail])
            {
                ans+=a[head];
                a[tail]-=a[head];
                head++;
            }
            else{
                ans+=a[head];
                head++;
                tail--;
            }
        }
    }
    cout<<ans;
    return 0;
}
