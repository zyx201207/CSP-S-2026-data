#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int y=a[i]&a[j];
				mx=max(mx,y);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		int sum=pow(2,a[i])-1;
		if(sum!=a[i]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	int fla=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			fla=0;
			break;
		}
	}
	if(fla==1){
		int g=n-m+1;
		int sum=log2(g);
		int ans=0;
		for(int i=sum;i>=1;i--){
			int k=pow(2,i);
			if(g>=k){
				g-=k;
				ans+=k;
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
