#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define ll long long
int hyw,T;
int n;
ll d;
ll a[N];
bool lt[N],rt[N];
int dis[N];
ll rds[N];
deque<int> q1;
int q2[N],fr,bk;
void print(deque<int> a){
	while(a.size()){
		cout<<a.front()<<" ";
		a.pop_front();
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(hyw==11||hyw==12/*||1*/){
		ll x=a[2]-a[1];
		int y=d/x;
//		cerr<<"hyw\n";
		ll ans=0;
		if(y==1||y==0){
			cout<<0<<endl;
			return;
		}
		if(y*2>n){
			cout<<0<<endl;
			return;
		}
		cout<<n-(y*2-1)<<endl;
		return;
	}else{
		ll ans=0;
		for(int k=1;k<=n;k++){
			dis[k]=0,rds[k]=1;
			while(q1.size())q1.pop_back();
			q1.push_back(k);
			fr=1,bk=0;
			q2[++bk]=1;
			for(int i=k+1;i<=n;i++){
//				dis[i]=0x3f3f3f3f;
//				rds[i]=0;
//				for(int j=i-1;j>=k&&a[i]-a[j]<=d;j--){
//					if(dis[i]>dis[j]+1){
//						rds[i]=rds[j];
//						dis[i]=dis[j]+1;
//					}else if(dis[i]==dis[j]+1){
//						rds[i]+=rds[j];
//					}
//				}
//				if(rds[i]==2)ans++;
				while(q1.size()&&a[q1.front()]+d<a[i]){
					q2[fr]-=rds[q1.front()];
					if(!q2[fr])fr++;
					q1.pop_front();
				}
				if(q1.empty())break;
//				cout<<k<<" "<<i<<"---------\n";
//				print(q1);
//				cout<<endl;
//				for(int i=fr;i<=bk;i++)cout<<q2[fr]<<" ";
//				cout<<endl;
				dis[i]=dis[q1.front()]+1;
				rds[i]=q2[fr];
				while(q1.size()&&dis[q1.back()]>dis[i])
					q1.pop_back(),bk--;
				if(q1.size()&&dis[q1.back()]==dis[i])
					q2[bk]+=rds[i];
				else q2[++bk]=rds[i];
				q1.push_back(i);
				if(rds[i]==2)ans++;
//				cout<<dis[i]<<" "<<rds[i]<<endl;
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cerr<<"really?\n";
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>hyw>>T;
//	cerr<<"really?\n";
	while(T--)/*cerr<<T<<endl,*/solve();
}
/*
0 234
6 2
1 2 3 4 5 6

*/
//22		C:\Users\Administrator\AppData\Local\Temp\ccDaZQjK.s	Error: value of 00000e8d5046e23b too large for field of 4 bytes at 0000000000000003
