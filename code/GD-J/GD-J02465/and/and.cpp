#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
long long a[200010],b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		if((a[1]+1)%2==0){
			sort(a+1,a+n+1,greater<int>());
			ans=a[1];
			for(int i=1;i<m;i++){
				ans&=a[i+1];
			}
			cout<<ans;
			return 0;
		}
		if(n==m){
			ans=a[1];
			for(int i=1;i<=n;i++){
				ans&=a[i+1];
			}
			cout<<ans;
			return 0;
		}
		if(m==n-1){
			b[1]=a[1];
			for(int i=2;i<=n;i++){
				b[i]=b[i-1]&a[i];
			}
			ans=b[n]&a[1];
			for(int i=2;i<=n;i++){
				int x=b[n]&b[i]+b[i-1];
				ans=max(ans,x);
			}
			cout<<ans;
		}
    } 
    else if(n<=2000&&n>20){
    	if(m==1){
    		sort(a+1,a+n+1,greater<int>());
    		cout<<a[1];
    		return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int x=a[i]&a[j];
					ans=max(ans,x);
				}
			}
			cout<<ans;
			return 0;
		}
		if(n==m){
			ans=a[1];
			for(int i=1;i<=n;i++){
				ans&=a[i+1];
			}
			cout<<ans;
			return 0;
		}
	}
	else if(n<=20){
		if(n==m){
			ans=a[1];
			for(int i=1;i<=n;i++){
				ans&=a[i+1];
			}
			cout<<ans;
			return 0;
		}
		if(n==1){
			cout<<a[1];
			return 0;
		}
	}
	return 0;
}
