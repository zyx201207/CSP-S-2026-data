#include<bits/stdc++.h>
using namespace std;
namespace std{
	using i64=long long;
	using u32=unsigned int;
	using u64=unsigned long long;
	using p32=pair<int,int>;
	using p64=pair<long long,long long>;
	#define all(x) (x).begin(),(x).end()
	#define one(x) (x).first
	#define two(x) (x).second
}
#define int long long
int n,D;
int a[2000005],to[2000005];
namespace ST{
	int fa[22][2000005],val[22][2000005];
	void pre_work(){
		fa[0][n+1]=(n+1);
		for(int i=n;i>=1;i--)
			{fa[0][i]=min(fa[0][i+1],i);val[0][i]=0;while(fa[0][i]>1&&(a[i]-a[fa[0][i]-1])<=D&&(fa[0][i]--));}
		for(int i=1;i<=20;i++)
			for(int j=1;j<=n;j++)
				{fa[i][j]=fa[i-1][fa[i-1][j]];val[i][j]=val[i-1][j]+val[i-1][fa[i-1][j]]+fa[i-1][j];}
	}
	int ask(int l,int r){
		int now=r,sum=0;
		for(int i=20;i>=0;i--)
			if(fa[i][now]>l)
				{sum+=(val[i][now]+fa[i][now]);now=fa[i][now];}
		return sum;
	}
	int solve(int p,int l,int r,int v){
		int ans=(r+1);
		while(l<=r){
			int mid=(l+r)>>1;
			if(ask(p,mid)>=v)
				{ans=mid;r=mid-1;}
			else	l=mid+1;
		}
		return ans;
	}
	int calc(int p,int l,int r,int val){
		if(l>r)	return 0;
		int mid=(l+r)>>1,now=ask(p,mid);
		if(now<val)	return calc(p,mid+1,r,val);
		if(now>(val+1))	return calc(p,l,mid-1,val);
		return solve(p,l,r,val+1)-solve(p,l,r,val);
	}
}
void work(bool CASE){
	cin>>n>>D;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
		{to[i]=max(to[i-1],i);while(to[i]<n&&(a[to[i]+1]-a[i])<=D&&(++to[i]));}
	int ans=0;ST::pre_work();
	for(int i=1;i<=n;i++){
		int pre=0;vector<int> sum;
		for(int j=i;to[j]!=j;j=to[j])	sum.push_back(to[j]);
		if(CASE==0){
			for(int j=1;j<sum.size();j++)
				{int nowl=(sum[j-1]+1),nowr=sum[j];pre+=sum[j-1];ans+=ST::calc(i,nowl,nowr,pre-1);}
		}
		else{
			for(int j=1;j<sum.size();j++){
				int nowl=(sum[j-1]+1),nowr=sum[j];pre+=sum[j-1];
				for(int k=nowl;k<nowr;k++)
					if(ST::ask(i,k)==(pre-1))
						ans+=(n-(k-i+1)+1);
			}
			break;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int CASE,T;cin>>CASE>>T;
	while(T--)	work(CASE>=11&&CASE<=12);
	return 0;
}