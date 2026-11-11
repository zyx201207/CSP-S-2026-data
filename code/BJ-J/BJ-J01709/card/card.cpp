#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int i,j,k,n,m=0,p,q,s,l,y;
    cin>>n>>m;
    int a[n],b[n],c[n],x[m]={0};
    for (i=0;i<n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    /*
    for (i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;*/
    for (i=0;i<n;i++)//ju
    {
        //cout<<endl<<i<<endl<<endl;
        s=0;
        for (y=0;y<n;y++)
        {
            a[y]=c[y];
            //cout<<a[y];
        }
        //cout<<endl;
        for (j=i;j<n;j++)//chupai
        {
            p=0;
            //cout<<j<<" dijizhang"<<endl;
            for (k=0;k<s;k++)//zhuomian
            {
                //cout<<"^";
                if (a[j]==b[k])//panding
                {
                    //cout<<"*";
                    for (l=k;l<s;l++)
                    {
                        a[l]=0;
                    }
                    a[k]=a[j];
                    s=k+1;
                    p=1;
                    break;
                }

            }
            //cout<<endl;
            //cout<<"a[j]="<<a[j]<<endl;
            //cout<<"s="<<s<<endl;
            if (p==0)
            {
                b[s]=a[j];
                //cout<<"b[s]="<<b[s]<<endl;
                q=s;
                s+=1;

            }
        }
        //cout<<"zhuomian"<<endl;
        for (j=0;j<s;j++)
        {
            //cout<<b[j]<<" ";
            x[b[j]-1]++;
        }
        //cout<<endl<<"jishu"<<endl;
        /*
        for (j=0;j<m;j++)
        {
            cout<<x[j]<<" ";
        }
        cout<<endl;*/
    }
    for (j=0;j<m;j++)
    {
        cout<<x[j]<<" ";
    }
    cout<<endl;
    return 0;
}
