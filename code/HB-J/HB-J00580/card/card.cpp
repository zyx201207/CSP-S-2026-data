#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005][2],head,tail,b[50005],c[50005];
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
    }
    for(int i=1;i<=n;i++)
    {
        head=i;
        tail=i-1;
        for(int j=head;j<=n;j++)
        {

            tail++;
            if(b[a[tail][0]]==0)
                b[a[tail][0]]=1;
            else
                for(int i=1;i<tail;i++)
                {

                    if((a[i][0]==a[tail][0])&&a[i][1]==0)
                    {
                        a[i][1]=1;
                        for(int j=i+1;j<tail;j++)
                        {
                            b[a[j][0]]=0;
                            a[j][1]=1;
                        }
                        break;
                    }
                }

        }
        for(int i=1;i<=m;i++)
        {
            if(b[i])
            {
                c[i]++;
            }

        }
        for(int i=1;i<=m;i++)
        {
            b[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            a[i][1]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }

	return 0;
}
