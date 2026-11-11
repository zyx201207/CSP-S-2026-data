#include<bits/stdc++.h>
using namespace std;
int p[10000010],x[500010];
int c,t,n,d;
void a(int s,int e,int l,int d)
{
    p[l]--;
    for(int i=e+1;i<=n;i++)
    {
        if(x[i]-x[e]<=d)
        {
            l+=(x[i]-x[e]);
            a(i,e,l,d);
        }
        else
            break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    bool A=true;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;i++)
        {
            cin>>x[j];
            if(n>=3&&j>=3&&(x[j]-x[j-1])!=(x[j]-x[j-2]))
            {
                A=false;
            }
        }
        if(A==true)
        {
            cout<<"0"<<endl;
            continue;
        }
        int ans=0;
        for(int j=1;j<n;j++)
        {
            for(int k=j+2;k<=n;k++)
            {
                int l=x[k]-x[i];
                a(j,k,l,d);
            }
        }
        sort(p+1,p+1+n);
        int j=1;
        while(p[j]<0)
        {
            if(p[j]==2)
                ans+=1;
            j++;
        }
        cout<<ans<<endl;
        for(int j=1;j<=n;i++)
        {
            x[j]=0;
        }
    }
    return 0;
    }
