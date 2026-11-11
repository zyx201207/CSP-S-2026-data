#include<bits/stdc++.h>
using namespace std;
long long a[500005],mx;
int n,m,b[105];
void dfs(int x,int y,long long z)
{
	if(x>m||y<1)return ;
	if(x==m)
	{
		mx=max(mx,z);
		return ;
	}
	for(int i=y;i>=1;i--)
	{
		dfs(x+1,i-1,(z&a[i]));
	}
}
int main(){
	ios::scny_with_stdio(false);cin.tie(0);cout.tie(0); 
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);	
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
		dfs(0,i,a[i]);
	}
   cout<<mx;
	return 0;
} 
