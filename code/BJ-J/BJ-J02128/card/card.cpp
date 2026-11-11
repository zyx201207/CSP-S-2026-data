#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int a[500005],stk[500005],b[300005],ans[300005];//b[] saves the first set the num appear in stk[]
int cnt[300005];
int top=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    //bool ba=1;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        //if(a[i]<a[i-1])ba=0;
    }
    /*if(ba==1)
    {
        for(i=1;i<=n;++i)
        {

        }
    }*/
    /*else */if(m==1)
    {
        cout<<n;
    }
    else if(m==2)
    {
        int e1=0,e2=0;
        for(int i=1;i<=n;++i)
            if(a[i]==1)e1=i;
            else if(a[i]==2)e2=i;
        for(int i=1;i<=n;++i)
        {
            ans[a[i]]++;
            if(a[i]==1 && e2==n)ans[2]++;
            else if(a[i]==2 && e1==n)ans[1]++;
        }
        cout<<ans[1]<<" "<<ans[2];
    }
    else
    {
        top=0;
        for(int i=1;i<=n;++i)
        {
            top=0;
            memset(stk,0,sizeof(stk));
            memset(cnt,0,sizeof(cnt));
            memset(b,0,sizeof(b));
            for(int j=i;j<=n;++j)
            {
                stk[++top]=a[j];
                if(b[a[j]]>0)
                {
                    for(int k=top;k>b[a[j]];--k)
                        if(k==b[stk[k]])
                        {
                            b[stk[k]]=0;
                        }
                    top=b[a[j]];
                }
                else
                    b[a[j]]=top;
            }
            for(int j=1;j<=top;++j)
                cnt[stk[j]]=1;
            for(int j=1;j<=m;++j)
                ans[j]+=cnt[j];
        }
        for(int j=1;j<=m;++j)
            cout<<ans[j]<<" ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
