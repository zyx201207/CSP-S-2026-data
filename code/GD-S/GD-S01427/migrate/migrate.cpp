#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],len[305][305],sum;
void dfs(int l,int r,int now,int dis){
	if(sum>2)return;
	if(now==r){
		sum++;return;
	}
	if(dis>=len[l][r])return;
	for(int i=r;i>now;i--)
	if(len[now][i]==1)
	dfs(l,r,i,dis+1);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=6)
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int k=1,lst=i;
			for(int l=i;l<=j;l++)
			{if(a[l]-a[lst]>d)
			{
				if(lst==l-1){k=-1;break;}
				else k++,lst=l;
			}
			}
			len[i][j]=k;
		}
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			sum=0;
			if(len[i][j]>1)
			dfs(i,j,i,0);
			if(sum==2)ans++;
		}
		cout<<ans<<endl;
	}
	else if(c==11||c==12){
		while(t--){
		cin>>n>>d;
		long long ans=0,k;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		k=d/(a[2]-a[1]);
		if(k>=2&&2*k<=n)
		ans=n-2*k+1;
		cout<<ans<<endl;
		}
	}
	return 0;
}
