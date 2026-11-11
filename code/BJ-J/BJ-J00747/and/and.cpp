#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
long long dfs(long long x,long long sum,long long o){
	if(sum==m){
		return x;
	}
	for(int i=o+1;i<=n;i++){
		if(o+1<=n){
			ans=max(ans,dfs(x&a[i],sum+1,o+1));
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
		}
		if(m==n){
			ans=a[1]&a[2];
			for(int i=3;i<=n;i++){
				ans=ans&a[i];
			}
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
	}else if(n<=200000){
		bool f=1;
		long long aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=4){
				f=0;
				break;
			}
			if(a[i]==1){
				aa++;
			}else if(a[i]==2){
				bb++;
			}else{
				cc++;
			}
		}
		if(f){
			if(cc>=m){
				cout<<3;
				return 0;
			}else if(bb>=m){
				cout<<2;
				return 0;
			}else if(bb+cc>=m){
				cout<<2;
				return 0;
			}else if(aa+cc>=m||aa>=m){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}else if(n<=20){
		for(long long i=1;i<=n;i++){
			if(n-i+1>=m){
				dfs(a[i],1LL,i);
			}
		}	
	}
	cout<<ans;
	return 0;
}
