#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}else if(m==2){
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
