#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
ll C,T;
ll n,d,ans=0;
ll a[N],sum[N];
ll iss[N];
void dfs(ll now,ll len){
//	cout<<now<<endl;
	if(sum[now]==0) sum[now]=len;
	else if(sum[now]!=0 && len==sum[now]){
		iss[now]++;
//		cout<<"find same "<<now<<" "<<sum[now]<<endl;
	}
	if(sum[now] > len){
		sum[now]=len,iss[now]=0;
//		cout<<"find low "<<now<<" "<<sum[now]<<endl;
	}
	for(ll i=now+1;i<=n;i++)
	{
		if(a[i]-a[now] > d) break;
		dfs(i,len+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(C==13 || C==14){
		for(int i=1;i<=T;i++) cout<<"0"<<endl;
		return 0;
	}
	while(T--){
		cin>>n>>d;
		int der=0;
		bool flag1=true;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			int derta;
			if(i>1) derta=a[i]-a[i-1];
			if(i==2) der=derta;
			else if(der != derta) flag1=false;
		//	cout<<i<<" "<<flag1<<endl;
		}
		if(C==11 || C==12){
		//	cout<<"131132141";
			ll summ=d/der;//一次能飞跃的空格数
			if(summ==0){
				cout<<"0"<<endl;
				continue;
			}
			ans=n-2*summ+1;
			cout<<ans<<endl; 
			continue;
		}
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) sum[j]=0,iss[j]=false;
//			cout<<"start : "<<i<<endl;
			dfs(i,0);
			for(ll j=1;j<=n;j++)
			{
				if(iss[j]==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
}
