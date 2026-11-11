#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=5e5+10,C=5010;
ll n,m;
ll a[N];
ll cost[C][C],pl[C];//5000部分分 pl:最优方案 
void solve1(){
	ll mn=1e18;
	int mnid;
	for(int j=1;j<=n;j++){//选中的数 
		ll dj=0;
		for(int i=1;i<=n;i++){//遍历 
			cost[j][i]=abs(a[i]-a[j]);
			dj+=cost[j][i];
		}
		if(dj<mn){
			mn=dj;
			mnid=j;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		pl[i]=cost[mnid][i];
	}
	sort(pl+1,pl+n+1);
	int idx=1;
	while(m>=0){
		m-=pl[idx];
		ans++;
		idx++;
	}
	cout<<ans-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag=1,flag2=1;//special A B
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=a[i]){
			flag=0;
		}
	}
	if(n<=5000){
		solve1();
	}else if(n<=500000&&flag){
//		ll dj2=(n%2==0?(n/2)*(n/2):n/2*(n/2-1));
		ll cs=0,ans=0;
		while(m>=0){
			if(cs==0){
				ans++;
				cs++;
				continue;
			}
			if(cs==n/2){
				if(n%2==0){
					m-=cs;
					ans++;
					break;
				}else{
					m-=cs;
					ans++;
					m-=cs;
					ans++;
					break;
				}
			}
			m-=cs;
			ans++;
			m-=cs;
			ans++;
			cs++;
		}
		cout<<ans;
	}else if(n<=500000&&flag2){
		//AK400
	}
	return 0;
} 
