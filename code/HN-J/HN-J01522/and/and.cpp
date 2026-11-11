#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	} 
	else if(m==n-1){
		long long sum=a[1];
		for(int i=2;i<=n;i++) sum=(sum&a[i]);
		for(int i=1;i<=n;i++){
			ans=max(ans,(sum&a[i]));
		}
		cout<<ans;
	}
	else{
		for(int i=0;i<(1<<n);i++){
			int h=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1) h++;
			}
			if(h!=m) continue;
			long long sum=-1; 
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					if(sum==-1) sum=a[j+1];
					else sum=(sum&a[j+1]);
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	return 0;
}
