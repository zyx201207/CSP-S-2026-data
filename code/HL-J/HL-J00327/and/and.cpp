#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long ll;
int n,m;
ll a[maxn];
int cnt=0,ans=-1,sum=0;
void dfs(int x);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
void dfs(int x){
	for(int i=x; i<=n; i++){
		int q=sum;
		if(cnt==0) sum=a[i];
		else sum=sum&a[i];
		cnt++;
		if(cnt==m){
			ans=max(ans,sum);
		}else{
			dfs(i+1);
		}
		cnt--;
		sum=q;
	}
}
