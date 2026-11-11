#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+20;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[N];
bool flag1=true;
void solve1(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(m<a[i]-1){
			cout<<ans;return;
		}
		m-=a[i]-1;ans++;
	}
	cout<<ans;
	return ;
}
ll ans=0;
void dfs1(int x){
	if(x>m){
		ll pvis[100]={},nvis[100]={},z=0;
		ll sum=-inf;
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				pvis[a[i]]++;
				sum=max(sum,pvis[a[i]]);
			}else if(a[i]==0){
				z++;
				sum=max(sum,z);
			}else if(a[i]<0){
				nvis[abs(a[i])]++;
				sum=max(sum,nvis[abs(a[i])]);
			}
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs1(x+1);
		a[i]--;
	}
}
ll diff;
void solve2(){
	ll sum=1;
	for(int i=1;i<=n;i++){
		//cout<<"now i="<<i<<" need="<<abs(diff)*i<<" m="<<m;
		if(m<abs(diff)*i){
			//cout<<"Not enought cout<<";
			cout<<sum;return ;
		}
		m-=abs(diff)*i;
		sum++;
		//cout<<"enough! m="<<m<<" sum="<<sum<<endl;
	}
	cout<<sum;
	return ;
}
bool flag2=true;
int vis[N];
ll cho[N],top=0;
void dfs2(int x){
	if(x>n){
		//cout<<"get another one\n";
		top=0;
		ll maxx=-inf;
		ll summ=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			cho[++top]=a[i];
			maxx=max(cho[top],maxx);
		}
		for(int i=1;i<=top;i++){
			summ+=abs(maxx-cho[i]);
			//cout<<cho[i]<<" diff summ+="<<abs(maxx-cho[i])<<endl;
			if(summ>m) return;
		}
		if(summ>m) return;
		ans=max(top,ans);
		//cout<<"AC,try upd ans="<<ans<<endl;
		return;
	}
	vis[x]=1;
	dfs2(x+1);
	vis[x]=0;
	dfs2(x+1);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=false;
		if(i==2) diff=a[i]-a[i-1];
		if(i!=1 and i!=2){
			if(a[i]-a[i-1]!=diff) flag2=false;
		}
	}
	if(m<=10 and n<=5){
		dfs1(1);
		cout<<ans;
	}else if(flag1){
		solve1();
	}else if(flag2){
		solve2();
	}else{
		dfs2(1);
		cout<<ans;
	}
	return 0;
}
