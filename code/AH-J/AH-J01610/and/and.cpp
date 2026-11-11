#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int n,m;
long long a[N],ans,cell=-1,maxn=-1,mx=-1;
bool p[N];
vector<long long> c;
void dfs(long long x,int k){
	if(k==m){
		mx=max(mx,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			p[i]=1;
			if(c.size()==0) x=a[i];
			c.push_back(a[i]);
			dfs(x&a[i],k+1);
			c.pop_back();
			p[i]=0;
		}
	}
}

int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		if(i==1) ans=a[i];
		ans&=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;	
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cell=max(cell,a[i]&a[j]);
			}
		}
		cout<<cell;
		return 0;
	}
	if(n<=20){
		dfs(0,0);
		cout<<mx;
		return 0;	
	}
	else{
		sort(a+1,a+1+n);
		long long op;
		op=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			op&=a[i];
		}
		cout<<op;
	}
	return 0;
}
