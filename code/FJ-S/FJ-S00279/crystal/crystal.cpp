#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll a[N],n,m,sum,ans=-0x7fffffffffffffff;
int zy[1050];
bool isa=true,isb=true,first=true;
void dfs(int depth,int now){
	a[now]+=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=17;i++){
		zy[a[i]]+=1;
	}
	ll maxn=-0x7fffffffffffffff;
	for(int i=1;i<=1017;i++)maxn=max(maxn,1LL*zy[i]);
	ans=max(ans,maxn);
	memset(zy,0,sizeof(zy));
	if(depth==m+1){
		return;
	}
	if(now>=n)return;
	for(int i=now;i<=n;i++){
		for(int j=depth;j<=m;j++){
			dfs(j,i);
			a[i]-=1;
		}
	}
}
ll featurea(int x,int cha){
	ll cnt=0,sum=cha;
	while(x>=0&&cnt<n-1){
		x-=sum;
		sum+=cha;
		if(x>=0&&cnt<n-1)cnt++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cha;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3){
			if(first){
				cha=a[i-1]-a[i-2];
				first=false;
			}
			isb=(a[i]==(a[i-1]+cha));
		}
		isa=(a[i]==i);
	}
	if(isa||isb){
		ll fea=featurea(m,cha);
		cout<<((fea>0)?fea+1:0)<<'\n';
		return 0;
	}
	if((!isb)&&(!isa)){
		dfs(1,1);
		cout<<ans<<'\n';
	}
	return 0;
}
