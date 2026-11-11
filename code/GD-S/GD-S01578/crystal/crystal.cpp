#include<iostream>
#include<algorithm>
using namespace std;
int n,ma=-1,ans[500010];
long long m,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++){
		long long sum=0;
		int j;
		for(j=i;j>=1;j--){
			sum+=a[i+1]-a[j];
			if(sum>m) break;
		}
		if(j==1) ans[i]=i-j+2;
		else ans[i]=i-j+1;
	}
	for(int i=1;i<n;i++) ma=max(ma,ans[i]);
	cout<<ma;
	return 0;
}
