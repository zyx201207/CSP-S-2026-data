#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[114514];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//=================================┓
	cin>>n>>m;                      //  ┤输入 
	for(int i=1;i<=n;i++)cin>>a[i]; //  ┤
	//=================================┛
	
	//====================================情况一:m=2  枚举
	if(m==2){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	} 
	//=====================================情况二：m=1 最大值：
	else if(m==1){
		int ans=INT_MIN;
		for(int i=1;i<=a[i];i++){
			ans=max(ans,a[i]);
		} 
		cout<<ans;
		return 0;
	}
	//=====================================情况三：m=n 自己算 
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	//====================================m=3
	else if(m==3){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<ans;
		return 0;
	} 
	//====================================m=4
	else if(m==4){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						ans=max(ans,(a[i]&a[j]&a[k]&a[l]));
					}
				}
			}
		}
		cout<<ans;
		return 0;
	} 
	//====================================m=5
	else if(m==5){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int h=l+1;h<=n;h++){
							ans=max(ans,(a[i]&a[j]&a[k]&a[l]&a[h]));
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	} 
	return 0;
}
