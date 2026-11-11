#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,cnti1=0,cnt=0;
    long long M;
    cin>>n>>M;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==i) cnti1++;//a[i]=i
    }

    int d=a[2]-a[1];
    for(int i=2;i<=n;i++)
    {
        if(abs(a[i]-a[i-1])==d) cnt++;//deng cha shu lie
    }
    if(cnti1==n)
    {
        int ans=0;
        long long m=M;
        for(int i=0;;i++)
        {
            m-=i;
            ans++;
            if(m=0) break;
            else if(m<0)
            {
                ans--;
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    if(cnt==n-1)
    {
        int sum=0,ans=0;
        long long x=M;
        while(x>0)
        {
            x-=sum;
            ans++;
            sum+=d;
        }
        if(x==0) cout<<ans;
        if(x<0) cout<<ans-1;
        return 0;
    }
    sort(a+1,a+n+1);
    int answer=0;
    for(int i=1;i<=n;i++)
    {
        int num=a[i],hm=0;
        long long alls=M;
        for(int j=i;j>=1;j--)
        {
            int dx=num-a[j];
            alls-=dx;
            hm++;
            if(alls<=0) break;
        }
        if(alls==0) answer=max(answer,hm);
    }
    cout<<answer;
    return 0;
}
