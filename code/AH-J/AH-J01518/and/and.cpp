#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,sum1[N],sum2[N];
/*

4 2
3 15 12 12

12

4 4
3 15 12 12

5 3
31 3 1 15 7

7
*/
void dfs(int pos,int tmp,int cnt) {
	if(tmp<ans)return ;
	if(pos>n) {
		if(cnt==m) {
			ans=tmp;
		}
		return ;
	}
	if(cnt==0) {
		dfs(pos+1,tmp,cnt);
		dfs(pos+1,a[pos],cnt+1);
	} else {
		dfs(pos+1,tmp&a[pos],cnt+1);
		dfs(pos+1,tmp,cnt);
	}
	return ;
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],mx=max(mx,a[i]);
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1)
	{
		sum1[1]=a[1];
		sum2[n]=a[n];
		for(int i=2;i<=n;i++)sum1[i]=sum1[i-1]&a[i];
		for(int i=n-1;i>=1;i--)sum2[i]=sum2[i+1]&a[i];
		ans=max(ans,sum2[2]);
		ans=max(ans,sum1[n-1]);
		for(int i=2;i<n;i++)
		{
//			if(i==2)cout<<(sum1[i-1])<<" "<<(sum2[i+1])<<"\n";
			ans=max(sum1[i-1]&(sum2[i+1]),ans);
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}

