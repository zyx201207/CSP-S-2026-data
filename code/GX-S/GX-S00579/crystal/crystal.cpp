#include<bits/stdc++.h>
using namespace std;
int a[500005],last[500005],toOneCris[500005];
int change(int l,int r)
{
    return toOneCris[r]-toOneCris[l]-l*(a[r]-a[l]);
}
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int N,m;
    cin>>N>>m;
    cin>>a[0];
    for(int i=1;i<N;i++)
    {
        cin>>a[i];
        last[i]=a[i]-a[i-1];
        toOneCris[i]=toOneCris[i-1]+last[i]*i;
    }
    int ans=0;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(change(i,j)<=m&&j-i+1>ans)
            {
                ans=j-i+1;
            }
            else if(change(i,j)>m)
            {
				continue;
			}
        }
    }
    cout<<ans;
   
    return 0;
}

