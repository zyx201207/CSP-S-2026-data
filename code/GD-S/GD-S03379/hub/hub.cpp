#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define Endl "\n",void()
#define End void()
#define make make_pair
namespace kong{bool st;}
const int N=5*1e5+7;
int c,t,id;
int n,k;
struct node{
	int nxt,to;
}e[N*2];
int cnt=0,head[N];
bool vis[N],flag[N],vis2[N];
void add(int x,int y){
	e[++cnt]={head[x],y};
	return head[x]=cnt,void();
}
int pop_count(int x){
	int res=0;
	if(x==0) return 0;
	while(x){
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
void white(int x){
	string s="";
	if(x==0) return cerr<<"0"<<Endl;
	while(x){
		if(x&1) s.push_back('1');
		else s.push_back('0');
		x/=2;
	}
	while(!s.empty()){
		cerr<<s.back();
		s.pop_back();
	}
	return cerr<<Endl;
}
void solve(){
	memset(head,0,sizeof(head));
	for(int i=1;i<=cnt;i++) e[i]={0,0};
	cnt=0;
	cin>>n>>k;
	for(int i=1,x,y;i<=n-1;i++){
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	deque<pair<int,int> > q;
	int ans=INT_MAX;
	for(int S=0;S<(1<<n);S++){
		int res=0;
//		cerr<<"in\n";
		if(pop_count(S)!=k) continue;
//		white(S);
		for(int i=0;i<n;i++){
			if((S>>i)&1) vis[i+1]=1;
			else vis[i+1]=0; 
			vis2[i+1]=0;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(!((S>>i)&1)) continue;
			if(vis2[i+1]==1) continue;
			if(cnt==2) goto noe;
			cnt++;
			q.clear();
			q.push_back(make(i+1,0));
			for(int j=1;j<=n;j++) flag[j]=0;
			flag[i+1]=1;
			while(!q.empty()){
				auto now=q.front();
				q.pop_front();
				for(int ii=head[now.first];ii;ii=e[ii].nxt){
					int y=e[ii].to;
					if(flag[y]==1) continue;
					if(vis[y]!=1) continue;
					flag[y]=1;
					vis2[y]=1;
					q.push_back(make(y,now.second+1));
				}
			}
		}
		for(int i=0;i<n;i++){
			if((S>>i)&1) continue;
			q.clear();
			q.push_back(make(i+1,0));
			for(int j=1;j<=n;j++) flag[j]=0;
			flag[i+1]=1;
			while(!q.empty()){
				auto now=q.front();
				q.pop_front();
				if(vis[now.first]==1){
					cnt++;
					res=max(res,now.second);
					break;
				}
				for(int ii=head[now.first];ii;ii=e[ii].nxt){
					int y=e[ii].to;
					if(flag[y]==1) continue;
					flag[y]=1;
					q.push_back(make(y,now.second+1));
				}
			}
		}
//		cerr<<"cnt::"<<cnt<<endl;
		ans=min(ans,res);
		noe:;
	}
	return cout<<ans<<Endl ;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
	cin>>id>>_;
	while(_--) solve(); 
	cerr<<endl<<kong::MB()<<endl;
	return 0;
} 
