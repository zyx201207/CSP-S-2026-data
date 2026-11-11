#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if((ans&a[j])!=ans) continue;
			sum+=((a[j]&(1<<i))>0);
		}if(sum>=m) ans+=(1<<i);
	}cout<<ans;
	return 0;
}
