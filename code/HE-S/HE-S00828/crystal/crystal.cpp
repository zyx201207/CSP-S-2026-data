#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	long long sum=0;
	for(int i=n;i>=1;i--){
		int j=i;
		while(a[i]-a[j]+sum<=m){
			sum+=a[i]-a[j];
			j--;
		}
		if(j>=0){
			ans=max(ans,i-j);
		}else{
			ans=max(ans,i);
		}
		sum=0;
	}
	cout<<ans;
	return 0;
}
