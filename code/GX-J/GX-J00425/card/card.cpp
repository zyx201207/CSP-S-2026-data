#include <bits/stdc++.h>
#define LL long long
#define AC return 0
using namespace std;
const int N=2e5+10;
int n,m,a[101];
inline void LI()
{
	cin>>n>>m;
    int ans[m],k=1;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    while(n--)
    {
        int tmp[n]={0},tp[m]={0};
        for(int i=k;i<=n;i++)
        {
            int sum=0;
            bool ok=1;
            for(int j=k;j<=i;j++)
                if(tmp[j]==a[i])
                {
                    ok=0,sum=j;
                    break;
                }
            if(!ok)
                for(int j=sum;j<=n;j++)
                    tmp[j]=0;
            tmp[i]=a[i];
        }
        for(int i=k;i<=n;i++)
            tp[tmp[i]]++;
        for(int i=1;i<=m;i++)
            ans[i]=tp[i];
        k++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int t=1;
//  cin>>t;
	while(t--)
		LI();
	AC;//rp+=INF
}
