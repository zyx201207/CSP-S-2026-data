#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans=0;
    int a[500010];
    int s[500010];
    bool A=true,B=true;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            A=false;
        }
        if(n>=3&&i>=3&&(a[i]-a[i-1])!=(a[i]-a[i-2]))
        {
            B=false;
        }
    }
    if(B==true||A==true)
    {
       int sum=0;
        int temp=0;
        int d=a[2]-a[1];
        while(m>sum)
        {
            temp+=d;
            sum+=temp;
        }
        if(sum==m)
        {
           ans=temp/d+1;
            cout<<ans<<endl;
            return 0;
        }
        else if(sum>m)
        {
            ans=temp/d;
            cout<<ans<<endl;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    s[1]=0;
    int num;
    int c=1;
    int p[500010];
    p[n]=1;
    for(int i=n;i>=1;i--)
    {
        p[i]=1;
        for(int j=i-1;j>=1;j--)
        {
            if(a[j]==a[i])
            {
                p[i]+=1;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        s[i]=0;
        c=p[i];
        for(int j=i-1;j>=1;j--)
        {
            if(j>=1&&s[i]<=m)
            {
                s[i]=s[i]+a[i]-a[j];
                c++;
            }
            else if(s[i]>m){
                break;
            }
        }
        if(c>ans)
        {
            ans=c-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
