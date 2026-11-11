#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main(){
	freopen("cyrstal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long s=0;
		for(int j=i;j<=n;j++){
			for(int k=j-i+1;k<=j;k++){
				s+=a[j]-a[k];
				if(s>m) break;
			}
			if(s<=m){
				if(ans<i){
					ans=i;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

