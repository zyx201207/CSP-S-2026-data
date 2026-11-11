#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i = 1;i <= n;i++){
			ans=max(ans,a[i]);
		}
		cout << ans;
	}else if(m==2){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i==j)continue;
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout << ans;
	}else if(m==n){
		ans=a[1];
		for(int i = 1;i <= n;i++){
			ans&=a[i];
		}
		cout << ans;
	}
	return 0;
}
