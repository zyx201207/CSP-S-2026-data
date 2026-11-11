#include<bits/stdc++.h>
#define int long long
int a[500005];
int b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	if(n<=5000){
		std::priority_queue<int,std::vector<int>,std::greater<int>> q[n+5];
		int ans=-1;
		for(int i=1;i<=n;i++){
			int num=a[i];
			for(int j=1;j<=n;j++){
				if(j!=i){
					q[i].push(std::abs(a[j]-a[i]));
				}
			}
		}
		for(int i=1;i<=n;i++){
			int ans1=1;
			int m1=m;
			while(!q[i].empty()){
				
				int it=q[i].top();
				q[i].pop();
				if(m1>=it){
					m1-=it;
					ans1++;
				}else break;
			}
			ans=std::max(ans,ans1);
		} 
		std::cout<<ans;
	}else {
		for(int i=2;i<=n;i++){
			b[i-1]=a[i]-a[i-1];
		}
		std::sort(b+1,b+n);
		int m1=m;
		int ans=0;
		for(int i=1;i<n;i++){
			if(m1>=b[i]){
				m1-=b[i];
				ans++;
			}
		} 
		std::cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
