#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long sum=m,num=0;
		for(int j=i;j>=1;j--){
			if(sum>=a[i]-a[j]){
				sum-=a[i]-a[j];
				num++;
			}else break;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
