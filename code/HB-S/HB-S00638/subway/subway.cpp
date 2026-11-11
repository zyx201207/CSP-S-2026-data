#include <bits/stdc++.h>
using namespace std;

int n,c,m,d,q,x,y;
int w[500010],k[510][500010],t[510][500010];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i][0];
        for(int j=1;j<=2*k[i][0];j++)
        {
            cin>>k[i][j];
        }
    }
    while(q--)
    {
        long long ans=0;
        cin>>x>>y;
        if(7<=c&&c<=11)
        {
			for(int i=1;i<=n;i++)
			{
				ans+=w[x]+w[y];
				if(x==y) break;
					if(k[i][1]==x)
					{
						x=k[i][3];
					}
					else if(k[i][3]==x)
					{
						x=k[i][1];
					}
					ans+=(k[i][2]+k[i][4]);
			}
            cout<<ans<<endl;
        }
        if(20<=c&&c<=21)
        {
            ans+=w[x]+w[y];
            for(int i=1;i<=2*k[1][0];i++)
            {
                for(int j=1;j<=2*k[2][0];j++)
                {
                    ;
                }
            }
			cout<<ans<<endl;
        }
    }
    return 0;
}
//fei le. xia chi zai lai ba.
