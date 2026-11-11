#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,x[2000005],h,t,l[2000005],r[2000005],c,f[2000005][2],q,ans,id[2000005],idd[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        ans=c=0;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
            f[i][0]=f[i][1]=l[i]=r[i]=id[i]=idd[i]=0;
        }
        h=t=1;
        for(;h<n;h++)
        {
            if(r[c]==n)break;
            while(1)
            {
                if(x[t+1]-x[h]>d||t==n)break;
                t++;
            }
            if(t==r[c])continue;
            l[++c]=h;
            r[c]=t;
            id[h]=c;
            idd[t]=c;
        }
        for(long long i=c-1;i>0;i--)if(id[r[i]])f[r[i]][1]=f[r[id[r[i]]]][1]+r[id[r[i]]]-r[id[r[i]]-1];
        //for(long long i=c;i>0;i--)cout<<f[r[i]][1]<<" ";
        for(long long i=2;i<=c;i++)if(idd[l[i]])f[l[i]][0]=l[idd[l[i]]+1]-l[idd[l[i]]]+f[l[idd[l[i]]]][0];
        //for(long long i=1;i<=c;i++)cout<<l[i]<<" "<<r[i]<<endl;
        for(long long i=1;i<c;i++)
        {
            if(id[r[i]-1]&&r[i]-1!=l[i])
            {
                q=id[r[i]-1];
                //cout<<i<<" "<<q<<endl;
                ans=ans+(l[i+1]-l[i]+f[l[i]][0])*(f[r[q]][1]+r[q]-r[q-1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
