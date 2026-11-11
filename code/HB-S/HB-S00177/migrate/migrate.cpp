#include<bits/stdc++.h>
using namespace std;
#define ll long long
//i'have drunk a cup of cafe but i still want to sleep
//or maybe i just have a headache...qwq
//that's terrible,just like i have a poor English grade but i can only speak English here!
//why!!!!!!!
//teacher says that we only need to see it as a exercise(maybe this sentence is wrong
//but my exercise is like a(thinking... bug!(laugh freely
//i can hardly think that how many spelling wrong showed in these sentencese
//please don't let my name show in the HBmihuoxingweidashang
//loving comes from 00177
const int maxn=2e6+5;
const long long inf=1ll*1e18;
int c,t,n,tag[maxn];
ll a[maxn],d,ans,dis[maxn];
vector<int> tree[maxn];
queue<int> q;
void bfs(int cnt){
	q.push(cnt);
	//cout<<cnt<<'\n';
//	for(int i=0;i<(int)tree[cnt].size();i++)cout<<tree[cnt][i]<<' ';
	//cout<<'\n'<<'\n';
	for(int i=cnt+1;i<=n;i++)dis[i]=inf,tag[i]=0;
	dis[cnt]=0;
	//for(int i=cnt;i<=n;i++)cout<<dis[i]<<' ';
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<(int)tree[u].size();i++){
			int v=tree[u][i];
		//	cout<<u<<" "<<v<<'\n';
		//	cout<<dis[v]<<' '<<dis[u]+1<<'\n';
			if(dis[v]>dis[u]+1){
	//			cout<<"bdc"<<'\n';
				tag[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}else if(dis[v]==dis[u]+1){
				tag[v]++;
				q.push(v);
			}
		}
	}
	for(int i=cnt+1;i<=n;i++){
		//cout<<tag[i]<<" ";
		if(tag[i]==2)ans++;
	}
	//cout<<'\n';
	return;
}
void deal(){
	//cout<<"nd"<<n<<' '<<d<<'\n';
	for(int i=1;i<=n;i++)cin>>a[i],tree[i].clear();
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
	//		cout<<i<<" "<<j<<" ";
	//		cout<<'\n';
			if(a[j]-a[i]<=d)tree[i].push_back(j);
			else break;
		}
//		for(int j=0;j<(int)tree[i].size();j++)cout<<tree[i][j]<<" ";
	//	cout<<'\n';
	}
	for(int i=1;i<n;i++)bfs(i);
	cout<<ans<<'\n';
}
int main(){
//	freopen("123.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	//cout<<t;
	while(t--){
		cin>>n>>d;
		ans=0;
	//	cout<<"rt"<<'\n';
		if(c<=10)deal();
		if(c==11||c==12){
			for(int i=1;i<=n;i++)cin>>a[i];
			ll dd=a[n]-a[n-1];
			ll p=d/dd;
			if(p<=1)cout<<0<<'\n';
			else{
				for(int i=1;i<=n;i++){
					if(i+2*p-1<=n)ans++;
					else break;
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}
