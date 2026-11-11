#include<bits/stdc++.h>
using namespace std;
long long a[999999];
long long m;
int n;
int ans=INT_MIN,sum;
bool vis[999999];
long long temp;
void dfs(long long k,int t){
	if(t>n||t<1||vis[t])return;
	if(temp==0){
		ans=max(sum,ans);
		return;
	}
	vis[t]=1;
	if(temp-abs(k-a[t])>=0){
		sum++;
		temp-=abs(k-a[t]);
	}
	dfs(k,t+1);
	dfs(k,t-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i-1]!=a[i])f1=0;
		}
	}
	if(f1){
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])f2=0;
	}
	temp=m;
	if(f2){
		ans=1;
		for(int i=n%2?n/2:n/2-1,j=n%2?n/2+2:n/2+1;temp>0&&i>=1&&j<=n;j++,i--){
			int mid=n%2?a[n/2+1]:a[n/2];
			if(temp-abs(mid-a[i])>=0){
				ans++;
				temp-=abs(mid-a[i]);
			}
			else{
				cout<<ans<<endl;
				return 0;
			}
			if(temp-abs(mid-a[j])>=0){
				ans++;
				temp-=abs(mid-a[j]);
			}
			else{
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],i);
		memset(vis,0,sizeof(vis));
		sum=0;
		temp=m;
	}
	cout<<ans<<endl;
	return 0;
}
