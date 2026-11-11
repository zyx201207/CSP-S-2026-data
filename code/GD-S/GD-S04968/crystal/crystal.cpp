#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll a[N],m,ans,cnt,k[N],sum,last;
inline int maxn(int x,int y){return ((x>y)?x:y);}
queue<ll>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)k[i]=a[i]-a[i-1];k[1]=0;
	for(int i=2;i<=n;i++)
	{
		cnt++;
		while(sum+k[i]*cnt>m)
		{
			sum-=last-a[i-cnt];
			cnt--;
		}
		if(sum+k[i]*cnt<=m)
			sum+=k[i]*cnt;
		last=a[i];
		ans=maxn(ans,cnt);
	}
	cout<<ans+1;
	return 0;
}
