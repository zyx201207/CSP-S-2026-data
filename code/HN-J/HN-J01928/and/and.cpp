#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;

int n,m;
int an[N];
int maxn;
int sum;

void dfs(int x,int depth,int num){
	//cout<<x<<" "<<depth<<" "<<num<<"\n";
	if(num>=m){
		//cout<<num<<"\n";
		maxn=max(maxn,x);
		return ;
	}
	if(depth>n) return ;
	if(x==0) dfs(an[depth],depth+1,1);
	dfs(x&an[depth],depth+1,num+1);
	dfs(x,depth+1,num);
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	sort(an+1,an+1+n);
	if(n>20 && n<=2000){
		if(m==1){
			cout<<an[n];
			return 0;
		} else if(m==n){
			sum=an[1];
			for(int i=2;i<=n;i++){
				sum&=an[i];
			}
			cout<<sum;
			return 0;
		} else {
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					maxn=max(maxn,an[i]&an[j]);
				}
			}
			cout<<maxn;
			return 0;
		}
	}
	else if(n>=2000 && (m==n-1 || m==n)){
		sum=an[1];
		for(int i=2;i<=n;i++){
			sum&=an[i];
		}
		if(m==n){
			cout<<sum;
			return 0;
		}
		for(int i=1;i<=n;i++){
			maxn=max(maxn,sum|!an[i]);
		}
		cout<<maxn;
		return 0;
	}
	else dfs(0,1,0);
	cout<<maxn;
	return 0;
}

