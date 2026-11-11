#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long dp[10001];
int xzA(){
	int ans=0;
	for(int i=n-1;i>a[1];i--){
		if(((a[1]+a[i])*(i-a[1]))/2<=m){
			ans=i;
			break;
		}
	}
	return ans;
}
void doans(){
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int c=0;
		bool is_over=false;
		for(int j=1;j<=i;j++){
			c+=a[i]-a[j];
			if(c==m){
				ans=i;
				is_over=true;
				for(int k=i+1;a[k]==a[i];k++){
					ans++;
				}		
				break;

			}
			else if(c>m){
				ans=i-1;
				is_over=true;		
				break;

			}
		}
		if(is_over)break;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	xzA();
	cin>>n>>m;
	bool xingzhiAB=true;
	int dc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)dc=a[2]-a[1];
		else if(i!=1)if(a[i]-a[i-1]!=dc)xingzhiAB=false;
	}
	if(xingzhiAB){
		cout<<xzA()<<endl;
	}
	else{
		doans();
	}
	return 0;
}

