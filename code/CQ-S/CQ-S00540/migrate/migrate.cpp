#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=2e6+5;
int C,T,n,nxt[N],lst[N];
long long m,a[N],ans[N];
struct node{
	int num[2],tag;
	node operator+(const node&oth)const{
		return {num[0]+oth.num[0],num[1]+oth.num[1]};
	}
}s[N<<2];
void build(int rt,int l,int r){
	s[rt]={1,0,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
	s[rt]=s[rt<<1]+s[rt<<1|1];
}
void pushtag(int rt,int val){
	if(val==1)s[rt].num[1]=s[rt].num[0],s[rt].num[0]=0;
	else if(val>1)s[rt].num[0]=s[rt].num[1]=0;
	s[rt].tag+=val;
}
void pushdown(int rt){
	pushtag(rt<<1,s[rt].tag),pushtag(rt<<1|1,s[rt].tag);
	s[rt].tag=0;
}
void update(int rt,int l,int r,int x,int y,int val){
	if(x>y)return;
	if(x<=l&&r<=y){pushtag(rt,val);return;}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(x<=mid)update(rt<<1,l,mid,x,y,val);
	if(y>mid)update(rt<<1|1,mid+1,r,x,y,val);
	s[rt]=s[rt<<1]+s[rt<<1|1];
}
int query(int rt,int l,int r,int x,int y){
	if(x>y)return 0;
	if(x<=l&&r<=y)return s[rt].num[1];
	pushdown(rt);
	int mid=(l+r)>>1,an=0;
	if(x<=mid)an+=query(rt<<1,l,mid,x,y);
	if(y>mid)an+=query(rt<<1|1,mid+1,r,x,y);
	return an;
}
pair<int,int>dp[N];
int c[N];
void update(int x,int val){for(;x<=n;x+=(x&(-x)))c[x]+=val;}
int query(int x){int an=0;for(;x>0;x-=(x&(-x)))an+=c[x];return an;}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&m);
		fre(i,1,n,1)scanf("%lld",&a[i]);
		int nx=n;
		rep(i,n,1,1){
			while(nx>i&&a[nx]-a[i]>m)nx--;
			nxt[i]=nx;
		}
		if(n<=300){
			fre(i,1,n,1){
				dp[i]={0,1},ans[i]=0;
				fre(j,i+1,n,1){
					dp[j]={0x3f3f3f3f,0};
					int now=j-1;
					while(now>=i&&a[j]-a[now]<=m){
						if(dp[j].first>dp[now].first+1)
							dp[j].first=dp[now].first+1,dp[j].second=dp[now].second;
						else if(dp[j].first==dp[now].first+1)
							dp[j].second+=dp[now].second;
						now--;
					}
					if(dp[j].first==0x3f3f3f3f)break;
					if(dp[j].second==2)ans[i]++;
				}
			}
		}
		else if(n<=5000){
			int ls=1;
			fre(i,1,n,1){
				while(ls<i&&a[i]-a[ls]>m)ls++;
				lst[i]=ls;
			}
			fre(i,1,n,1){
				dp[i]={0,1},ans[i]=0;
				fre(j,0,n,1)c[j]=0;
				update(i,1);
				fre(j,i+1,n,1){
					if(lst[j]==j)break;
					dp[j]={0x3f3f3f3f,0};
					int l=max(lst[j],i),r=j-1,an=l;
					while(l<=r){
						int mid=(l+r)>>1;
						if(dp[mid].first==dp[an].first)
							an=mid,l=mid+1;
						else r=mid-1;
					}
					dp[j].first=dp[an].first+1,dp[j].second=query(an)-query(max(lst[j],i)-1);
					update(j,dp[j].second);
					if(dp[j].second==2)ans[i]++;
				}
			}
		}
		else{
			build(1,1,n);
			rep(i,n,1,1){
				if(nxt[i]-i==0)ans[i]=0,update(1,1,n,i+1,n,2);
				else if(nxt[i]-i==1)ans[i]=ans[nxt[i]];
				else{
					ans[i]=nxt[nxt[i]-1]-nxt[nxt[i]-2];
					if(nxt[nxt[i]-1]==nxt[nxt[i]]&&nxt[nxt[i]-2]!=nxt[nxt[i]])
						ans[i]+=query(1,1,n,nxt[nxt[i]]+1,n);
				}
				update(1,1,n,i+1,nxt[i],1);
			}
		}
//		fre(i,1,n,1)cerr<<nxt[i]<<' ';cerr<<'\n';
//		fre(i,1,n,1)cerr<<ans[i]<<' ';cerr<<'\n';
//		cerr<<"-----------------------\n";
		long long sum=0;
		fre(i,1,n,1)sum+=ans[i];
		printf("%lld\n",sum);
	}
	return 0;
}
