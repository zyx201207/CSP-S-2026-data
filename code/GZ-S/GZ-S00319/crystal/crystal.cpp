//GZ-S00319 ·½Åæç÷
#include <iostream>
using namespace std;
int n,cntmax=0,L=1;
bool done=true;
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    int tree[n]={};
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%lld",&t);
        tree[i]=t;
    }
    if(m>100000000&&n>5000)
    {
        int R=L+1,cnt=1,tm=m;
        while(R<=n)
        {
            tm-=(tree[R]-tree[R-1])*(R-L);
            if(tm<0)
            {
                if(cntmax<cnt)cntmax=cnt;
                break;
            }
            R++;
            cnt++;
            if(R>n)
            {
                if(cntmax<cnt)cntmax=cnt;
                break;
            }
        }
    }
    else
    {
    do
    {
        done=true;
        for(int i=1;i<=n/2;i++)
        {
            if(tree[i]>tree[i+1])
            {
                int t=tree[i];
                tree[i]=tree[i+1];
                tree[i+1]=t;
                done=false;
            }
            if(tree[n-i]>tree[n-i+1])
            {
                int t=tree[n-i];
                tree[n-i]=tree[n-i+1];
                tree[n-i+1]=t;
                done=false;
            }
        }
    }while(!done);
    while(L<=n-1)
    {
        int R=L+1,cnt=1,tm=m;
        while(R<=n)
        {
            tm-=(tree[R]-tree[R-1])*(R-L);
            if(tm<0)
            {
                if(cntmax<cnt)cntmax=cnt;
                break;
            }
            R++;
            cnt++;
            if(R>n)
            {
                if(cntmax<cnt)cntmax=cnt;
                break;
            }
        }
        L++;
    }
    }
    printf("%d",cntmax);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
