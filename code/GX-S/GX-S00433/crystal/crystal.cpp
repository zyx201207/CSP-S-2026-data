 #include <bits/stdc++.h>
 using namespace std;
 long long n,m,a[500009],maxn=0,sum=0,b,c[500009];
 int main()
 {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++)
    {
        b=m;
        for(long long j=1;j<=n;j++)
        {
            c[j]=a[j];
        }
        for(long long j=1;j<i;j++)
        {
            if(c[i]-c[j]>b)
            {
                c[j]+=b;
                b=0;
                break;
            }
            else
            {
                b-=c[i]-c[j];
                //cout<<c[i]<<" "<<c[j]<<" "<<c[i]-c[j]<<endl;
                c[j]=c[i];
            }
        }
        sum=0;
        for(long long  j=1;j<=n;j++)
        {
            //cout<<a[j]<<" ";
            if(c[j]==c[i])
                sum++;
        }
        //cout<<endl;
        //cout<<sum<<" "<<i<<" "<<c[i]<<" "<<maxn<<endl;
        /*if(maxn==max(maxn,sum))
        {
            for(long long  j=1;j<=n;j++)
            {
                cout<<c[j]<<" ";
            }
            cout<<endl;
        }*/
        maxn=max(maxn,sum);
    }
    cout<<maxn;
    return 0;
 }
