#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans<(a[i]&a[j])){
				ans=(a[i]&a[j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

