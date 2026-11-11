#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans[200005];
//guanzhu bilibili dahongdou009
//guanzhu luogu 884813
//☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭
//❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂
//这下100%要AFO了，T2不会写我真的服了/ll/ll
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int b[200005]={},p=n;
        for(int j=i;j<=n;j++)
        {
            b[j]=a[j];
            int l=0,r=0;
            for(int k=1;k<=j-1;k++){if(b[k]==b[j]&&b[k]!=0){l=k;r=j;break;}}
            //cout<<l<<'\n';
            if(l==0)continue;
            for(int k=l;k<=r-1;k++)
            {
                b[k]=0;p--;
            }
        }
        for(int k=1;k<=n;k++)if(b[k])ans[b[k]]++;
        //for(int k=1;k<=n;k++)cout<<ans[k]<<' ';
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}

