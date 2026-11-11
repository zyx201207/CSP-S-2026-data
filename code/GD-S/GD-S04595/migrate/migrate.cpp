#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n,c,T,f[N],ans1,ans,sum;
long long d,x[N];
void dfs(int s,int m,int de){
	if(s == de){
		if(m < ans){
			ans = m;
			sum = 1;
		}
		else sum++;
		return ;
	}
	if(m > ans) return ;
	if(s > n) return;
	for(int i = s+1;i<=f[s];i++){
		dfs(i,m+1,de);
	}
}
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		int j = 1;
		for(int i = 1;i<=n;i++){
			while(x[j] - x[i] <= d&&j <=n) j++;
			j--;
			f[i] = j;
		}
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				ans = 200005,sum = 0;
				dfs(i,0,j);
				if(sum == 2) ans1++;
			}
		}
		cout<<ans1<<"\n";
	}
	return 0;
}
