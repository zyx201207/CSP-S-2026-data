#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long x[N];
long long sl[N],sr[N],L[N],R[N];
bool vis[N];
int main()
{
    freopen("migrate.in","r",stdin);
       freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c<=6)
    {
    while(t--)
    {
        long long n;
      	long long d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
        long long a;
            cin>>a;
            x[i]=a;
        }
        for(long long i=1;i<=n;i++)
        {
            long long l=1,r=i;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if(x[i]-x[mid]<=d)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            L[i]=r+1;
            l=i,r=n;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if(x[mid]-x[i]<=d)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            R[i]=l-1;
           // cout<<L[i]<<' '<<R[i]<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
        	//cout<<i<<' '<<n<<endl;
        	for(int j=i+3;j<=n;j++)
		{
		//cout<<j<<endl;
			int u=i;
			while(1)
			{
				vis[u]=1;
				if(R[u]==u)break;
				if(R[u]<j)u=R[u];
				else break;
			}if(u!=j&&R[u]==u)
			{
			
			u=i;
			while(1)
			{
				vis[u]=0;
				if(R[u]==u)break;
				if(R[u]<j)u=R[u];
				else break;
			}
			break;
			}
			u=j;
			vis[j]=1;
			int cnt=0,id=0,idd=0;
			//cout<<i<<' '<<j<<"*\n";
			while(1)
			{
				if(vis[u]==0)cnt++,id=u;
				//cout<<u<<' ';
				vis[u]=0;
				if(L[u]>i)u=L[u];
				else break;
			}
			//cout<<endl;
			//cout<<cnt<<endl;
			vis[j]=0;
			vis[i]=0;
			u=i;
			while(1)
			{
				if(vis[u]==1)
				{
					cnt++;
					idd=u;
				}
				//cout<<u<<' ';
				vis[u]=0;
				if(R[u]<j)u=R[u];
				else break;
			}
			//cout<<endl;
			//cout<<ans<<endl;
			if(cnt==2&&abs(id-idd)==1)ans++;
		}
		//cout<<ans<<endl;
        }
        cout<<ans<<'\n';
    }
    }
    else
    {
    int tt=0;
    while(t--)
    {
        tt++;
        long long n;
        long long d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(long long i=1;i<=n;i++)
        {
            long long l=1,r=i;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if(x[i]-x[mid]<=d)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            L[i]=r+1;
            
            l=i,r=n;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if(x[mid]-x[i]<=d)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            R[i]=l-1;
           // cout<<L[i]<<' '<<R[i]<<endl;
        }
        L[n+1]=n;
        R[0]=1;
        for(long long i=1;i<=n;i++)
        {
            sl[i]=1;
            if(L[i]!=i&&R[L[i]]==i)
            {
                sl[i]+=sl[L[i]];
                //cout<<i<<' '<<sl[i]<<endl;
                sl[i]+=(L[i+1]-1)-(L[i]+1)+1;
                //cout<<sl[i]<<endl;
            }
        }
        for(long long i=n;i>=1;i--)
        {
            sr[i]=1;
            if(R[i]!=i&&L[R[i]]==i)
            {
                sr[i]+=sr[R[i]];
                sr[i]+=R[i]-1-(R[i-1]+1)+1;
            }
        }
        long long ans=0;
       // for(long long i=1;i<=n;i++)cout<<sl[i]<<' '<<sr[i]<<endl;
        for(long long i=2;i<n-1;i++)
        {
            if(L[i]==i||R[i+1]==i+1||R[i]==i||L[i+1]==i+1)continue;
            if(R[L[i]]==i+1&&L[R[i+1]]==i)
            {
                ans+=1ll*(min(i,L[i+2])-1-(L[i+1]+1)+1+sl[L[i]])*(sr[R[i+1]]+R[i]-1-(max(i+1,R[i-1])+1)+1);
            }
            else
            {
                //if(tt==4)cout<<"NO\n";
                ans+=(R[i]-(max(i+1,R[i-1])+1)+1)*(min(i,L[i+2])-1-L[i+1]+1);
               // cout<<i<<' '<<R[i]<<' '<<R[i-1]<<endl;
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<'\n';
    }
    }
    return 0;
}