#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
bool cmp(int x,int y){
    return x>y;
}
int len(int x){//返回位数-1
    int i=1,ret=0;
    while(i<=x)
    {
        i*=2,ret++;
    }
    return ret-1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int i=len(a[m-1]),d;
    while(i>=0)
    {
        d=pow(2,i);
        ans+=d;
        for(int j=0;j<n;j++)
        {
            if(a[j]>=d)
            {
                a[j]=a[j]%d;//比m个数中最小值的最大值的最高位更高的数位是无用的
            }
            else
            {
                a[j]=0;//数值不到d的数不能纳入考虑范围
            }
        }
        sort(a,a+n,cmp);
        i=len(a[m-1]);
    }
    printf("%d",ans);
    return 0;
}