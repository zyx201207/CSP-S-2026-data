#include<iostream>
using namespace std;
long long n,m,dat[200005],maxn=0,maxnum=0,jl=0;
bool used[200005];
void dfs(long long ji,long long cnt){
	jl++;
	if(jl==100000000){
		cout<<maxnum;
		exit(0);
	}
	if(ji==m){
		maxn=max(maxn,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			if(ji==0) dfs(ji+1,dat[i]);
			else dfs(ji+1,(cnt&dat[i]));
			used[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		for(int i=1;i<=n;i++){
			cin>>dat[i];
			if(i==1) maxnum=dat[i];
			else maxnum&=dat[i];
		}
		cout<<maxnum;
		return 0;
	}
	if(n==m-1)
	for(int i=1;i<=n;i++){
		cin>>dat[i];
		maxnum=max(maxnum,dat[i]);
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
