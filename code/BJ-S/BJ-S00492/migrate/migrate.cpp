#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
long long d,val[N];
int dis[N],cnt[N],tmpcnt[N];
void subtask1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=i;
		for(int j=0;j<=n;j++) tmpcnt[j]=cnt[j]=dis[j]=0;
		cnt[0]=tmpcnt[0]=1;
		deque<int> q;
		q.push_back(0);
		for(int j=i+1;j<=n;j++){
			while(pos<j&&val[j]-val[pos]>d) q.pop_front(),tmpcnt[dis[pos]]-=cnt[pos],pos++;
			if(pos==j) break;
			if(tmpcnt[q.front()]==2) ans++;
			dis[j]=(q.front()+1),cnt[j]=tmpcnt[q.front()],tmpcnt[dis[j]]+=cnt[j];
			q.push_back(dis[j]);
		}
	}
	cout<<ans<<'\n';
}
void subtask2(){
	int pos=1;
	for(int j=0;j<=n;j++) tmpcnt[j]=cnt[j]=dis[j]=0;
	cnt[0]=tmpcnt[0]=1;
	deque<int> q;
	q.push_back(0);
	for(int j=2;j<=n;j++){
		while(pos<j&&val[j]-val[pos]>d) q.pop_front(),tmpcnt[dis[pos]]-=cnt[pos],pos++;
		if(pos==j) break;
		dis[j]=(q.front()+1),cnt[j]=tmpcnt[q.front()],tmpcnt[dis[j]]+=cnt[j];
		q.push_back(dis[j]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==2) ans+=n-i+1;
	}
	cout<<ans<<'\n';
}
void subtask3(){
	int pos;
	for(int i=1;i<=n;i++){
		if(max(val[i]-val[1],val[n]-val[i])<=d){
			pos=i;break;
		}
	}
	int ans=0;
	for(int i=max(1,pos-5);i<=pos;i++){
		int pos=i;
		for(int j=0;j<=n;j++) tmpcnt[j]=cnt[j]=dis[j]=0;
		cnt[0]=tmpcnt[0]=1;
		deque<int> q;
		q.push_back(0);
		for(int j=i+1;j<=n;j++){
			while(pos<j&&val[j]-val[pos]>d) q.pop_front(),tmpcnt[dis[pos]]-=cnt[pos],pos++;
			if(pos==j) break;
			if(tmpcnt[q.front()]==2) ans++;
			dis[j]=(q.front()+1),cnt[j]=tmpcnt[q.front()],tmpcnt[dis[j]]+=cnt[j];
			q.push_back(dis[j]);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>val[i];
		if(n<=5000){
			subtask1();
			continue;
		}
		if(c==13||c==14){
			subtask3();
			continue;
		}
		subtask2();
	}
	return 0;
}
