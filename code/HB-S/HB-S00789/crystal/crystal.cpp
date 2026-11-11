#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long sum=0;
long long a[N],maxn[N];
int cnt[2005];
int ans=0;
struct node{
	long long cha,pos;
}b[N];
void dfs(int pos,int sheng){
	if(pos==n)return;
	if(sheng==0){
		int maxn=-1000;
		for(int i=1;i<=n;++i){
			cnt[a[i]+100]++;
			maxn=max(maxn,cnt[a[i]+100]);
		}
		ans=max(maxn,ans);
		memset(cnt,0,sizeof cnt);
		return;
	}
	for(int j=0;j<=min((int)a[n]-(int)a[1],sheng);++j){
		if(a[pos]+j<a[pos+1])continue;
		a[pos]+=j;
		dfs(pos+1,sheng-j);
		a[pos]-=j;
	}
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
    sort(a+1,a+1+n);
    long long s=a[2]-a[1];
    for(int i=1;i<=n;++i){
		if(i!=1)if(a[i]-a[i-1]!=s)f=0;
		if(i!=n){
		    b[i].cha=a[i+1]-a[i];
		    b[i].pos=i;
		}
		maxn[i]=a[n]-a[i];
		sum+=maxn[i];
	}
	if(m>=sum){
		cout<<n;
		return 0;
	}
	if(f){
		int jia=b[1].cha;
		for(long long i=1;;++i){
			long long s=jia*i;
			ans=i;
			if(ans>=n)break;
			if((s+jia)*(s/jia)/2>m)break;
		}
		if(ans!=0)cout<<ans;
		else cout<<1;
		return 0;
	}
	dfs(1,m);
	cout<<ans;
    return 0;
}
