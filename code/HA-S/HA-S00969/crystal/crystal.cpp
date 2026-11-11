#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j>1;j--){
			if(a[j]<a[j-1]){
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i+1]){
			continue;
		}
		int mm=m,sum=1;
		for(int j=i-1;j>=1;j--){
			if(mm>=a[i]-a[j]){
				mm=mm-(a[i]-a[j]);
				sum++;
			}
			else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
