//第一短路等于第二短路小于第三短路？
//最短路贪心？次短路怎么求来者。。。
//事已至此，捞一下性质A送的分得了。
#include<bits/stdc++.h>
using namespace std;
int a[2000050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int g=a[2]-a[1];
        int f=d/g;
        //printf("n=%d,f=%d,d=%d,g=%d\n",n,f,d,g);
        int ans=n-(f*2)+1;
        if(f<0)f=-f;
        if(f==0||f==1||f>=n)ans=0;
        printf("%d\n",ans);
    }
}
