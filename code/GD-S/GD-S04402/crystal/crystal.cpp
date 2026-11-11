#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,M;
int a[N];
int num[N],mp[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>M;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int now=a[1],id=1;mp[1]=a[1],num[1]++;
	for(int i=1;i<=n;i++){
		if(now<a[i]) id++,now=a[i],mp[id]=a[i];
		num[id]++;
	}
	int ans=0;
	for(int i=id,sum;i>=1;i--){
		now=i-1,sum=num[i];
		int m=M;
		while(m>0&&now>=1){
			int awa=num[now]*(mp[i]-mp[now]);
			if(m>=awa) m-=awa,sum+=num[now];
			else sum+=(m/(mp[i]-mp[now])),m=0;
			now--;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
