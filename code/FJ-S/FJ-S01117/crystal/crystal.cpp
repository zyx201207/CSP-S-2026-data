#include<bits/stdc++.h>
using namespace std;
int const L=1e+5;
long long n,m,cnt,a[L],zj,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=m;
		for(int j=i;j>=1;j--){
			if(cnt>=(a[i]-a[j])){
				cnt-=(a[i]-a[j]);
				ans++;
			}
		}
		sum=max(sum,ans);
		ans=0;
	}
	cout<<sum;
	return 0;
}
