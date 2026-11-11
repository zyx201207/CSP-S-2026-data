//the end
//wish good luck

#include <bits/stdc++.h>
#define int long long
using namespace std;

auto fr=[]()->void
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	return;
};

const int N=5e5+10;
int a[N],b[N];
signed main()
{
	fr();
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=1;j<=n;j++)
		{
			if(a[j]>x){
				b[j]=LLONG_MAX;
			}else{
				b[j]=x-a[j];  
			}
		}
		
		sort(b+1,b+n+1,[&](int x,int y){
			return x<y;
		});
		
		int j=0,sum=0,cnt=0;
		while(++j<=n and sum<=m and b[j]!=LLONG_MAX){
			++cnt; sum+=b[j];
		}
//		
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<' ';
//		}
		
		ans=max(ans,cnt);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
