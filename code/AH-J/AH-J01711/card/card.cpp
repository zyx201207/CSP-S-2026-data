#include<bits/stdc++.h>
using namespace std;
const int N=5*100005;
int n,m,n1;
long long a[N],b[N],c[N],ans[N];
bool st[N];
int main()
{
	
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    n1=n;
    while(n--)
    {
		int sum=0;
		memset(b,0,sizeof b);
		memset(c,0,sizeof b);
		memset(st,false,sizeof st);
		for(int i=n1-n;i<=n1;i++)
		{
			sum++;
			if(st[a[i]]==false){
				b[sum]=a[i];
				st[a[i]]=true;
				c[a[i]]=sum;
			}
			else if(st[a[i]]==true){
				for(int j=c[a[i]];j<sum;j++) {b[j]=0;}
				c[a[i]]=sum;
				b[sum]=a[i];
			}
		}
		for(int i=1;i<=sum;i++) {
			if(b[i]!=0){
				ans[b[i]]++;
			}	
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
