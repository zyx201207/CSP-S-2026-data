#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int MAXN=2e6+5;
int c,t,n,d,x[MAXN],nxt[MAXN],cnt;
bool f;
void dfs(int s,int t,int len,int dep){
//	cout<<s<<" "<<t<<" "<<len<<" "<<dep<<"\n";
	if(dep>len)return ;
	if(f)return ;
	if(s>t)return ;
	if(s==t){
		cnt++;
		if(cnt>2){
			f=1;
			return ;
		}
	}
	for(int i=nxt[s];i>=s;i--)dfs(i,t,len,dep+1);
}
void solve1(){
	for(int i=1;i<=n;i++){
		int l=i,r=n,res=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]<=x[i]+d){
				res=mid;
				l=mid+1;
			}else r=mid-1;
		}
		nxt[i]=res;
//		cout<<";;"<<x[res]<<" "<<x[i]+d<<"\n";
//		cout<<";"<<i<<" "<<res<<"\n";
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
//			cout<<"1234";
			int l=i,len=0;
			bool flag=0;
			while(l<j){
				if(l==nxt[l]){
					flag=1;
					break;
				}
				l=nxt[l];
				len++;
			}
			if(flag)continue;
			f=0;
			cnt=0;
			dfs(i,j,len,0);
			if(cnt!=2)continue;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	int c=x[2]-x[1];
	int k=(int)(d/c);
	int p=k*2-1;
	int ans=0;
	if(p>n)ans=0;
	else if(p==0)ans=0;
	else if(c>=d)ans=0;
	else ans=n-2*k+1;
	cout<<ans<<"\n";
}
void calc(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(c>=1&&c<=2)solve1();
	else if(c>=11&&c<=12)solve2();
	else solve1();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)calc();
	return 0;
}
/*
1 2
6 2
-4 -3 -2 -1 3 6
T3 migrate
1~2 dfs暴力：
	枚举l,r 
	贪出最短路径d
	再dfs判断是否为…… 
	dfs(int u,int dep) 
	if(dep>d)return ;
	if(f)return ;
	if(u==r){
		cnt++;
		if(cnt>2){
			f=1;
			return ;
		}
	}
11~12 数学推导 ： 
	int c=a[i]-a[i-1];
	int k=(int)(d/c);
	ans=n-2*k+2;
*/
