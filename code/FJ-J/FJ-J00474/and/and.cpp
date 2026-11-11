#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;

int a[maxn],ans,n,m;

bool cmp(int x,int y){
	return x > y;
}

void dfs(int x,int sum,int cnt,bool ok){
	if(x>n){
		if(cnt==m)ans=max(ans,sum);
		return;
	}
	int sum2;
	if(!ok){
		dfs(x+1,a[x],cnt+1,1);
		dfs(x+1,sum,cnt,0);
	}
	else {
		dfs(x+1,(sum&a[x]),cnt+1,1);
		dfs(x+1,sum,cnt,1);	
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	else if(m==2 && n<=2000){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				res=max(res,(a[i]&a[j]));
			}
		}
		cout<<res;
		return 0;
	}
	else if(m==n){
		int res=a[1];
		for(int i=2;i<=n;i++){
			res=(res&a[i]);
		}
		cout<<res;
		return 0;
	}
	else {
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	return 0;
}
