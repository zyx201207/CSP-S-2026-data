#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll m,n,sum,his=0;
ll a[200010];
bool b[200010];

void dfs(int step,int x){
	if(step==m+1){
		his=max(sum,his);
		return;
	}
	if(n-x<m-step)return ;
	for(int i=x;i<=n;i++){
		if(b[i]!=1&&step!=1){
			b[i]=1;
			int t=sum;
			sum=(sum&a[i]);
			dfs(step+1,i+1);
			b[i]=0;
			sum=t;
		}
		else if(step==1&&b[i]==0){
			sum=a[i];
			b[i]=1;
			dfs(step+1,i+1);
			b[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<his;
	return 0;
}

