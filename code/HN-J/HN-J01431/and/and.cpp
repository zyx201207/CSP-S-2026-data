#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool f[200005];
void dfs(int x,int cnt,int sum){
	if(sum>n) return ;
	if(cnt==m){
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		dfs(x,cnt,sum+1);
		f[i]=1;
		dfs(x&a[i],cnt+1,sum+1);
		f[i]=0;
	}
}
bool flaga(){
	for(int i=1;i<=n;i++){
		int m=a[i];
		m++;
		while(m!=1){
			if(m%2==0) m/=2;
			else return false;
		}
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int maxx=0,maxin=2147483647;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		maxin&=a[i];
	}
	if(m==1){
		cout<<maxx;
	}
	else if(m==n){
		cout<<maxin;
	}
	else if(m==2){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i;j++){
				maxx=max(maxx,a[j]&a[j+i]);
			}
		}
		cout<<maxx;
	}
	else if(m==n-1){
		maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,maxin|a[i]);
		}
		cout<<maxx;
	}
	else if(flaga()){
		sort(a+1,a+n+1);
		reverse(a+1,a+1+n);
		cout<<a[m];
	}
	else if(!f){
		for(int i=1;i<=n;i++){
			
		}
	}
	else if(n<=20){
		dfs(2147483647,0,1);
		cout<<ans;
	}
	return 0;
}

