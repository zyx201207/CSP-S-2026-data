#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	int z=0,p=0,q=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(p>a[i]-a[i-1]) q=1;
		p=a[i]-a[i-1];
		if(a[i]!=i) z=-1;
	}
	if(z==0){
		long long ans=1,s1=0;
		while(m>0){
			s1++;
			if(m>=s1){
				m-=s1;
				ans++;
				if(m>=s1){
					m-=s1;
					ans++;
				}else{
					cout<<ans;
					return 0;
				}
			}else{
				cout<<ans;
				return 0;
			}
		}
	}else if(q==0){
		long long ans=1,s1=0;
		while(m>0){
			s1+=p;
			if(m>=s1){
				m-=s1;
				ans++;
				if(m>=s1){
					m-=s1;
					ans++;
				}else{
					cout<<ans;
					return 0;
				}
			}else{
				cout<<ans;
				return 0;
			}
		}
	}else if(n<=5000&&m<=1000000000){
		int ans=1,sum1=m;
		for(int i=1;i<=n;i++){//当位置为i时
			int sum=1;//当位置为i时的最大数量 
			int j=1;//滚木 
			int xx=i+j,yy=i-j;//左与右的变化量 
			while(sum1>=1){
				while(xx<=n&&yy>=1&&a[xx]-a[i]<a[i]-a[yy]&&sum1>=a[xx]-a[i]){
					sum++;
					xx+=1;
					sum1-=a[xx]-a[i];
				}
				while(xx<=n&&yy>=1&&a[xx]-a[i]>a[i]-a[yy]&&sum1>=a[i]-a[yy]){
					sum++;
					yy-=1;
					sum1-=a[yy]-a[i];
				}	
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}else{
		cout<<n/2;
	}
	return 0;
}
