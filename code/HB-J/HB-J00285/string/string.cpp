#include <bits/stdc++.h>

using namespace std;
long  a[200005];
char b[200005];

int main()
{
    long ans=0;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%ld %c",a+i,b+i);
    }
    int head=1,tail=n;
    while(n!=1&&n!=0)
    {
        int p=min(a[head],a[tail]);
        if(b[head]!=b[tail])ans+=p;
        if(a[head]>a[tail])a[head]-=a[tail],tail--,n--;
        else if(a[head]<a[tail])a[tail]-=a[head],head++,n--;
        else if(a[head]==a[tail])head++,tail--,n-=2;
    }
    printf("%ld",ans);
}
