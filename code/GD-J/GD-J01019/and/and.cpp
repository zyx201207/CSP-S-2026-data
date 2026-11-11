#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100005],ans=0,ax[50],ay[50],ac[50];
int th(int x,int y){
	memset(ax,0,sizeof(ax));
	memset(ay,0,sizeof(ay));
	memset(ac,0,sizeof(ac)); 
	while(x){
		ax[++ax[0]]=x%2,x/=2;
	}
	while(y){
		ay[++ay[0]]=y%2,y/=2;
	}
	for(int i=1;i<=max(ay[0],ax[0]);i++){
		if(ax[i]==ay[i])ac[i]=1;
	}
	ac[0]=max(ax[0],ay[0]);
	while(ac[ac[0]]==0)ac[0]--;
	int cc=0,sum=0;
	for(int i=1;i<=ac[0];i++){
		sum+=ac[0]*(1<<cc);
		cc++;
	}
	return sum;
}
void dfs(int idx,int sum,int lt){
	if(lt<=0){
		ans=max(ans,sum);
		return;
	}
	if(idx>n){
		return;
	}
	dfs(idx+1,sum,lt);
	dfs(idx+1,(sum&a[idx]),lt-1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx=max(mx,(a[i]&a[j]));
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==n){
		int sum=(1<<31)-1;
		for(int i=1;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	else if(n<=20){
		dfs(1,(1<<31)-1,m);
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		int sum=(1<<31)-1,mx=0;
		for(int i=1;i<=n;i++)sum=(sum&a[i]);
		for(int i=1;i<=n;i++){
			mx=max(mx,th(sum,a[i]));
		}
	}
	return 0;
}
//60/50
