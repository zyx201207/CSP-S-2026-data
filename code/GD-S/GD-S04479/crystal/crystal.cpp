#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,m,a[N],dis[N];
long long ans=0;
bool ts=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) ts=0;
	}
	if(ts){
		long long sum=0,ans=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>=m){
				ans=i;
				if(sum>m) ans--;
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(dis,0,sizeof(dis));
		long long x=a[i],cnt=0,mm=m,t=0,sum=0;
		bool jz=0;
		//当前以x为基准 
		for(int j=1;j<=n;j++){
			long long y=x-a[j];
			if(y<0) continue;
			sum+=y;
			cnt++;
			dis[cnt]=y;
			if(sum>m){
				jz=1;
				break;
			}
		}
		if(jz) continue;
		sort(dis+1,dis+1+cnt);
		for(int j=1;j<=cnt;j++){
			mm-=dis[j];
			t++;
			if(mm<=0) break;
		}
		if(mm<0) t--;
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
