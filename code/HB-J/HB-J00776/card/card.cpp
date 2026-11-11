#include <bits/stdc++.h>
using namespace std;
int n,m,c[500002],num[300002],tmp[500002],k;
bool b[500002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    num[n]=1;
    for(int i=1;i<n;i++)
    {
        memset(b,0,sizeof(b));
        memset(tmp,0,sizeof(tmp));
        k=0;
        for(int j=i;j<=n;j++)
        {
            if(b[c[j]]==false)
            {
                tmp[++k]=c[j];
                b[c[j]]=true;
            }
            else
            {
                while(tmp[k]!=c[j])
                {
                    b[c[k]]=false;
                    tmp[k]=0;
                    k--;
                }
                b[c[k]]=false;
                tmp[k]=0;
                k--;
            }
        }
        for(int j=1;j<=k;j++)
        {
            num[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<num[i]<<' ';
    }
    return 0;
}
