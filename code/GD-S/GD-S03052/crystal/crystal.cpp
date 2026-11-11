#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long sum=m,num=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>sum)break;
			sum-=(a[i]-a[j]);
			num++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
