#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
int fro[200005];
int beh[200005];
unsigned long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %c",&a[i],&b[i]);
    }
    int temp=1;
    for(int i=1;i<=n;i++)
    {
        fro[i]=temp;
        temp+=a[i];
    }
    fro[n+1]=temp;
    temp=1;
    for(int i=n;i>=1;i--)
    {
        beh[n-i+1]=temp;
        temp+=a[i];
    }
    beh[0]=temp;    
    int froi=1;
    int behi=1;
    int begin1=fro[froi];
    int end1=fro[froi+1]-1;
    int begin2=beh[behi];
    int end2=beh[behi+1]-1;
    while(froi+behi<=n)
    {
        if(b[froi]!=b[n-behi+1])
        {
            int min_be=max(begin1,begin2);
            int min_en=min(end1,end2);
            ans+=min_en-min_be+1;//+1
        }
        if(end1<end2)
        {
            froi++;
            begin1=fro[froi];
            end1=fro[froi+1]-1;
        }
        else if(end2<end1)
        {
            behi++;
            begin2=beh[behi];
            end2=beh[behi+1]-1;
        }
        else{
            froi++;
            behi++;
            begin1=fro[froi];
            end1=fro[froi+1]-1;
            begin2=beh[behi];
            end2=beh[behi+1]-1;
        }
    }
    printf("%lld",ans);
    return 0;
}