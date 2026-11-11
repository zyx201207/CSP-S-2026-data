#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+10];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (m==1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	long long ans=0;
	if(m==2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<=n;j++){
				long long q=a[i]&a[j];
				ans=max(ans,q);
			}
		}
	}
	if(m==3){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<=n;j++){
				for(int k = j+1;k<= n;k++)
				{
					long long q=a[i]&a[j]&a[k];
					ans=max(ans,q);
				}
			}
		}
	}
	if(m==4){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<=n;j++){
				for(int k = j+1;k<= n;k++)
				{
					for(int h=k+1;h<=n;h++){
						long long q=a[i]&a[j]&a[k]&a[h];
						ans=max(ans,q);
					}
					
				}
			}
		}
	}
	if(m==5){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<=n;j++){
				for(int k = j+1;k<= n;k++)
				{
					for(int h=k+1;h<=n;h++){
						for(int w=h+1;w<=n;w++){
							long long q=a[i]&a[j]&a[k]&a[h]&a[w];
							ans=max(ans,q);
						}
					}
					
				}
			}
		}
	}
	cout << ans;
	return 0;
}
