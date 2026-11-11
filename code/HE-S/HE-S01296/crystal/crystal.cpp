#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long cha=0;
	long long ans=1;
	long long cnt=1;
	for(int i=n;i>=1;i--){
		cnt=1;
		cha=0;
		for(int j=i-1;j>=1;j--){
			cha+=(a[i]-a[j]);
			if(cha<=m){
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
		if(ans==n){
			cout<<n;
			return 0;
		}
	}
	cout<<ans;
	return 0;
} 
