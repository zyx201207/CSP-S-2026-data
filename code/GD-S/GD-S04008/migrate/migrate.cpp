#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
const int N=2e6+5,inf=1061109567;
int C,T,n;
ll d,a[N],ans;
int nxt[N],lst[N],f[N],g[N];
deque<int>q;
void subtask1(){
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)
				f[j]=inf,g[j]=0;
			f[i]=0;g[i]=1;
			q.clear();q.push_back(i);
			int sum=0;
			for(int j=i+1;j<=n;j++){
				while(!q.empty()&&a[j]-a[q.front()]>d)sum-=g[q.front()],q.pop_front();
				if(sum<=0&&!q.empty()){
					sum=0;
					for(int i=0;i<q.size()&&f[q[i]]==f[q[0]];i++)sum+=g[q[i]];
				}
				if(!q.empty()&&sum==2)ans++;
				if(!q.empty())
					f[j]=f[q.front()]+1,
					g[j]=sum;
				while(!q.empty()&&f[j]<f[q.back()])q.pop_back();
				q.push_back(j);
			}
		}
		cout<<ans<<"\n";
	}
	return;
}
int sum[N];
void solve(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)sum[i]=1;
		int pos=1;
		for(int i=1;i<=n;i++){
			while(a[i]-a[pos]>d)pos++;
			lst[i]=pos;
		}
		pos=n;
		for(int i=n;i>=1;i--){
			while(a[pos]-a[i]>d)pos--;
			nxt[i]=pos;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			sum[nxt[i]]+=sum[i];
			if(lst[i]<i-1){
//				cout<<i<<": "<<lst[i]<<" "<<lst[lst[i]]<<" "<<lst[lst[i]+1]<<"\n";
				if(lst[lst[i]+1]==lst[i]);
				else if(lst[lst[i]]==lst[lst[i]+1])ans+=sum[lst[i]+1]-1;
				else ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	if(C<=10)subtask1();
	else solve();
	return 0;
}
