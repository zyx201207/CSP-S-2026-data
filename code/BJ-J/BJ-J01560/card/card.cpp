#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500100];
bool freeze[500100];
bool pluss[300050];
int kapaichuxiancishu[300050];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool have=false;
        for(int j=1;j<=i-1;j++)
        {
            if(have==true)
            {
                freeze[j]=true;
            }
            else if(a[j]==a[i]&&freeze[j]==false)
            {
                have=true;
                freeze[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(freeze[i]==false)
        {
            kapaichuxiancishu[a[i]]++;
            pluss[i]=true;
        }
    }
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<freeze[i]<<" ";
    //}
    //cout<<endl;
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<pluss[i]<<" ";
    //}
    //cout<<endl<<endl;
    for(int i=2;i<=n;i++)
    {
        if(freeze[i-1]==false)
        {
            pluss[i-1]=false;
            for(int j=i;j<=n;j++)
            {
                if(pluss[j]==true)
                {
                    kapaichuxiancishu[a[j]]++;
                }
            }
            //continue;
        }
        else if(freeze[i-1]==true)
        {
            ////解冻
            //for(int j=i;j<=n;j++)
            //{
            //    if(a[j]==a[i-1])
            //    {
            //        for(int k=i;k<=j-1;k++)
            //        {
            //            freeze[k]=false;
            //        }
            //        break;
            //    }
            //}
            //重新计算冰冻
            for(int j=i;j<=n;j++)
            {
                freeze[j]=false;
            }
            for(int j=i+1;j<=n;j++)
            {
                bool have=false;
                for(int k=i;k<=j-1;k++)
                {
                    if(have==true)
                    {
                        freeze[k]=true;
                    }
                    else if(a[k]==a[j]&&freeze[k]==false)
                    {
                        have=true;
                        freeze[k]=true;
                    }
                }
            }
            //重新计算哪些加过
            for(int j=1;j<=n;j++)
            {
                pluss[j]=false;
            }
            for(int j=i;j<=n;j++)
            {
                if(freeze[j]==false)
                {
                    kapaichuxiancishu[a[j]]++;
                    pluss[j]=true;
                }
            }
        }
        //
        //for(int j=1;j<=n;j++)
        //{
        //    cout<<freeze[j]<<" ";
        //}
        //cout<<endl;
        //for(int j=1;j<=n;j++)
        //{
        //    cout<<pluss[j]<<" ";
        //}
        //cout<<endl<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<kapaichuxiancishu[i]<<" ";
    }
    return 0;
}
//CSP-J   AK  I !!!   at 11:50