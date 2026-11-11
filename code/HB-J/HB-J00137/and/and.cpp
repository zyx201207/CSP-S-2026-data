#include<iostream>;

using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


     int n;
     int m;
     int ans=1;
     int as[31]={0};
     int e=0;
     int f=0;
     int o=0;
     int p=0;
     int a[200000]={0};
     int b[200000][31]={0};
     int c[200000]={0};
     int d[31]={0};
     int sizeb[20000]={0};
     int lastsize=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }



    for(int i=0;i<n;i++)
    {
        if(a[i]==1||a[i]==2||a[i]==3)
        {
            if(a[i]==1)
            {
                b[i][0]=1;
                c[i]=1;
            }
             if(a[i]==2)
            {
                b[i][0]=0;
                b[i][1]=1;
                c[i]=1;
            }
            if(a[i]==1)
            {
                b[i][0]=1;
                b[i][1]=1;
                c[i]=2;
            }
        }
        else
        {
            for(int j=0;j<31;j++)
            {
                d[j]=0;
            }
            e=0;
            b[i][0]=a[i];
            while(b[i][0]>1)
            {
                d[e]=b[i][0]%2;
                b[i][0]/=2;
                e++;
                if(b[i][0]/2==1)
                {
                    d[e]=0;
                    e++;
                    d[e]=1;
                    b[i][0]=1;
                }
            }
            sizeb[i]=e;
            for(int j=0;j<e;j++)
            {
                if(d[j]==1)
                {
                   c[i]+=1;
                }
                b[i][j]=d[j];

            }
        }

    }


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(o==c[j])
            {
                if(a[p]<a[j])
                {
                   p=j;
                }

            }
            else
            {
                if(o<c[j])
                {
                    o=c[j];
                    p=j;
                }
            }
        }

        if(i==0)
        {
            for(int j=0;j<sizeb[p];j++ )
            {
                as[j]=b[p][j];
            }
        }
        else
        {
            lastsize=max(lastsize,sizeb[p]);
             for(int j=0;j<lastsize;j++ )
            {
                if(as[j]==1&&b[p][j]==1)
                {
                    as[j]==1;
                }
                else
                {
                    as[j]=0;
                }
            }
        }
    }

    for(int i=0;i<lastsize;i++)
    {
        if(as[i]==1)
        {
            if(i=0)
            {
                ans++;
            }
            else
            {
                ans*=2;
            }
        }
    }
    cout<<ans<<endl;
}
