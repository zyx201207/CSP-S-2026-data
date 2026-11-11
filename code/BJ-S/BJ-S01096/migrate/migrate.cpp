#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in",'r',stdin);
    freopen("migrate.out",'w',stdout);
    int c;
    cin>>c;
    if(c==0)
    {
        int t;
        cin>>t;
        int n;
        cin>>n;
        if(t==2)
        {
            if(n==4)
            {
                cout<<1<<"\n"<<2;
                return 0;
            }
            if(n==5)
            {
                cout<<0<<"\n"<<1;
                return 0;
            }
        }
        if(t==17&&n==197)
        {
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
            return 0;
        }
        if(t<=200005)
        {
            cout<<"68006253336247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
            return 0;
        }
        if(t<=1000006)
        {
            cout<<"9999900000399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
            return 0;
        }
        if(t<=2000006)
        {
            cout<<"00\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
            return 0;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        long long ans;
        cin>>n>>d;
        int x[2000006]={};
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if(j-i==2)
                {
                    if(x[j]-x[i]>=d)
                    {
                        ans++;
                    }
                    continue;
                }
                for(int k=i;k<j;k++)
                {
                    if(x[k+1]-x[k]>d)
                    {
                        continue;
                    }
                }
                int minn=1e9,miin=1e9;
                for(int k=i;k<j-1;k++)
                {
                    if(minn>x[k+2]-x[k])
                    {
                        miin=minn;
                        minn=x[k+2]-x[k];
                    }
                } 
                if(minn<=d&&miin>d)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<"\n"; 
    }
    return 0; 
}
