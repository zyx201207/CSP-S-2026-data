#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	for(int i=m+1;i<=n;i++){
		for(int j=1;j<i;j++){
			cnt=a[i];
			for(int k=1;k<i;k++){
				if(k!=j){
					cnt=(cnt&a[k]);
				}
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
} 
