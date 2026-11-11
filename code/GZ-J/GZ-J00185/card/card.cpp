//GZ-J00185 ³ÂÕýÁú
#include<bits/stdc++.h>
using namespace std;
int a[300005],b[500005];
bool bl[300005],cancel[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<3001;i++)
        {
            cancel[i]=0;
            bl[i]=0;
        }
        for(int i=k;i<n;i++)
        {
            a[b[i]]++;
            if(bl[b[i]]==0) bl[b[i]]=1;
            else
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(!cancel[j])
                    {
                        cancel[j]=1;
                        a[b[j]]--;
                        bl[b[j]]=0;
                    }
                    if(b[j]==b[i])
                    {
                        break;
                    }
                }
                bl[b[i]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
	return 0;
}
