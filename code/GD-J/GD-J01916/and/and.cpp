#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans,a[N],c[N],w[N],t[N],g[N];
bool b[N][30],book[N];
void dfs(long long k){
	if(k>m){
		long long sum=a[c[1]];
		for(int i=2;i<=m;i++)
			sum&=a[c[i]];
		if(sum>ans)ans=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			c[k]=i;
			book[i]=1;
			dfs(k+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==2){
		long long tmp;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				tmp=(a[i]&a[j]);
				if(tmp>ans)ans=tmp;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=N&&m==n-1){
		for(int i=1;i<=n;i++){
			long long tmp=a[i];
			while(tmp>0){
				b[i][++w[i]]=tmp%2;
				tmp/=2;
			}
			for(int j=25;j>=1;j--)t[25-j+1]=b[i][j];
			for(int j=1;j<=25;j++)b[i][j]=t[j];
			for(int j=1;j<=25;j++){
				if(t[j]==0)c[j]++;
			}
		}
		for(int i=1;i<=25;i++){
			if(c[i]==0)t[i]=1;
			else t[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=25;j++)g[j]=t[j];
			for(int j=1;j<=25;j++){
				if(b[i][j]==0&&c[j]==1){
					g[j]=1;
				}
			}
			long long s=1,sum=0;
			for(int j=25;j>=1;j--){
				sum+=s*g[j];
				s*=2;
			}
			if(sum>ans)ans=sum;
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long tmp;
		for(int i=n;i>=1;i--){
			tmp=(a[i]&a[i-1]);
			if(tmp>ans)ans=tmp;
		}
		cout<<ans;
		return 0;
	}
	ans=a[n];
	for(int i=n;i>=n-m+1;i--)ans&=a[i];
	cout<<ans;
	return 0;
}
