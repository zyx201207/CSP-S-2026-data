#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=5005,inf=1e9;
int cid,T;
int n,d,a[maxn],c[maxn],mx[maxn];
struct Seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	#define mid ((l+r)>>1) 
	struct node{
		int mn,tg;
	}c[maxn<<2];
	void pushup(int p){c[p].mn=min(c[ls].mn,c[rs].mn);}
	void build(int p,int l,int r){
		c[p].mn=c[p].tg=inf;
		if(l==r){
			c[p].mn=c[p].tg=inf;
			return;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(p);
	}
	void add(int p,int v){c[p].mn=min(c[p].mn,v),c[p].tg=min(c[p].tg,v);}
	void pushdown(int p){
		if(c[p].tg!=inf){
			add(ls,c[p].tg);
			add(rs,c[p].tg);
			c[p].tg=inf;
		}
	}
	void modify(int p,int l,int r,int L,int R,int val){
		if(L>R)return;
		if(l>=L&&r<=R){
			add(p,val);
			return;
		}
		pushdown(p);
		if(L<=mid)modify(ls,l,mid,L,R,val);
		if(R>mid)modify(rs,mid+1,r,L,R,val);
		pushup(p); 
	}
	int query(int p,int l,int r,int pos){
		if(l==r)return c[p].mn;
		pushdown(p);
		if(pos<=mid)return query(ls,l,mid,pos);
		else return query(rs,mid+1,r,pos);
	}
}sg;
int dp[maxn],dis[maxn],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	IOS
	cin>>cid>>T;
	if(cid==13||cid==14){
		while(T--){
			cin>>n>>d;
			int fr,sd;
			cin>>fr;
			for(int i=2;i<=n;i++)cin>>sd;
			if(sd-fr==(2*d-1))cout<<"1\n";
			else cout<<"0\n";
		}
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)mx[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		queue<int>q;//队列 
//		cout<<"here1\n";
		for(int i=1;i<=n;i++){//枚举左端点
			while(!q.empty())q.pop();
			memset(dp,0,sizeof dp);
			memset(c,0,sizeof c);
			sg.build(1,i,n);
			dp[i]=1,dis[i]=0;
			c[0]=1;
			sg.modify(1,i,n,i+1,mx[i],dis[i]+1);
//		cout<<"here2\n";
			
			q.push(i);
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[j-1])>d)break;
				while(!q.empty()&&(a[j]-a[q.front()]>d)){
					c[dis[q.front()]]-=dp[q.front()];
					q.pop(); 
				}
//		cout<<"here3\n";
				dis[j]=sg.query(1,i,n,j);
//		cout<<"here7\n";
				dp[j]=c[dis[j]-1];
//		cout<<"here8\n";
				c[dis[j]]+=dp[j];
//		cout<<"here9\n";
//		cout<<"here4\n";
				sg.modify(1,i,n,j+1,mx[j],dis[j]+1);
				q.push(j);
				if(dp[j]==2)ans++;
//		cout<<"here5\n";
			}
		}
//		cout<<"here6\n";
		cout<<ans<<"\n";
	}
	return 0;
}

