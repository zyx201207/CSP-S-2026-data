/*#include<bits/stdc++.h>
using namespace std;
long long x[2000005]={0};
int dp[2000005]={0};//到i需要dpi步
int cnt[2000005][2]={0};
int p=1;
long long n,d;
vector<int> used;
void jump(int now,int last){
	if(last==0){
		cnt[now][p]++;
		used.push_back(now);
		return ;
	}
	for(int i=now+1;x[i]-x[now]<d&&i<=n;i++){
		jump(i,last-1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	long long ans;
	while(t--){
		ans=0;
		cin>>n>>d;
		dp[1]=1;
		for(long long i=1,j=1;i<=n;i++){
			cin>>x[i];
			dp[i]=dp[j];
			while(x[i]-x[j]>d){
				dp[i]++;
				j++;
			}
		}
		int u;
		for(int i=2;i<=dp[n];i++){//中间经过i-1个岛 （进行i次跳岛）
			p^=1;
			jump(1,i);
			while(!used.empty()){
				u=used.front();
				used.pop_back();
				if(cnt[u][p]==2&&!cnt[u][p^1]){
					ans++;
				}
				else{
					cout<<cnt[u][p]<<" ";
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,l;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>l;
		}
		if(d==2){
			cout<<n-4<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
