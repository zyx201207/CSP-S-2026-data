#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=a[i]&a[j];
				ans=max(ans,cnt);
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					cnt=a[i]&a[j]&a[k];
					ans=max(ans,cnt);
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
