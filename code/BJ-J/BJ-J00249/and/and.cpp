#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool f[200005][40];
bool flag[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			if((1<<j)&a[i]){
				f[i][j]=1;
			}
		}
	}
	for(int i=30;i>=0;i--){
		long long cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j][i] && !flag[j]){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!f[j][i] && !flag[j]){
					flag[j]=1;
				}
			}
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
