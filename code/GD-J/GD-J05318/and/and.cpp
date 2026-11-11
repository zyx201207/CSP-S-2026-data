#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int b=a[i]&a[j];
				ans=max(ans,b);
			}
		}
		cout<<ans;
	}
	return 0;
} 
