#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long sum,n,mid,p;
long long i,j;
long long ans;
char b[100005];
int l=0;
int pan()
{
    long long h1=sum-a[p]+1;
    int h2=1-l;
    if (h1<mid && mid<sum)
    {
        if (sum-mid-h2>mid-h1)//right>left
        {
            a[p]=sum-2*mid+h1-h2;
            i=p,j=p-1;

        }
        else if (sum-mid-h2<mid-h1)
        {
            a[p]=mid-2*sum-h1+h2;
            i=p+1,j=p;
        }
        else
        {
            a[p]=0;
            i=p+1,j=p-1;
        }

    }
    else if (mid==h1)
    {
        a[p]-=1;
        a[p]-=h2;
        i=p,j=p-1;

    }
    else
    {
        a[p]-=1;
        if (h2 && b[p]==b[p+1])
        {
            a[p+1]-=1;
        }
        else if (h2 && b[p]!=b[p+1])
        {
            a[p+1]-=1;
            ans+=1;
        }
        i=p+1,j=p;
    }
    return 0;

}
int fp()
{
    long long su=0;
    for (int k=1;k<=n;k++)
    {
        su+=a[k];

        if (su>=mid)
        {
            p=k;
            sum=su;
            return 0;
        }

    }
    return 0;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int k=1;k<=n;k++)
    {
        cin>>a[k]>>b[k];
        sum+=a[k];

    }
    mid=(sum+1)/2;
    l=sum%2;
    fp();

    pan();
    while (i<=n && j>=0)
    {
        long long v1=a[i],v2=a[j],a1=i,a2=j;
        if (a[i]>a[j]) a[i]-=a[j],j--;
        else if (a[i]<a[j]) a[j]-=a[i],i++;
        else i++,j--;
        if (b[a1]!=b[a2])
        {
            ans+=min(v1,v2);
        }

    }
    cout<<ans;






    fclose(stdin);
    fclose(stdout);
    return 0;
}
