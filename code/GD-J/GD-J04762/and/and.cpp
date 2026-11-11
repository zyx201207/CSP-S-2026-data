#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,Max=-1;
bool vis[N];
long long a[N];
void dfs(long long cnt,long long num){
	if(num==m){
		Max=max(cnt,Max);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(cnt&a[i],num+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]+1)>0&&(((a[i]+1)&a[i])==0));
		else flag=0;
	}
	if(flag){
		sort(a+1,a+1+n);
		cout<<a[n-m+1]<<"\n";
		return 0;
	}
    for(int i=1;i<=n;i++){
    	vis[i]=1;
    	dfs(a[i],1);
    	vis[i]=0;
	}
    cout<<Max<<"\n";
	return 0;
}
