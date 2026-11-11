#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans;
int a[N],w[35];

inline void dfs(int s,int p,int sum){
	sum&=a[p];
	if(s==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=p+1;i<=n;i++)
		dfs(s+1,i,sum);
}
inline int add(int i){
	int x=a[i],y=0;
	while(x){
		if(x&1)
			w[y]++;
		y++;
		x>>=1;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		int t=log2(a[i]+1);
		if(pow(2,t)-1!=a[i])
			f=false;
		cin>>a[i];
	}
	if(f){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else if(n<10000){
		a[0]=pow(2,31)-1;
		dfs(0,0,pow(2,31)-1);
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			int t=add(i),s=0;
			for(int j=t;j>=0;j--){
				if(w[j]>=m)
					s+=pow(2,j);
			}
			ans=max(ans,s);
		}
		cout<<ans;
	}
	return 0;
}
