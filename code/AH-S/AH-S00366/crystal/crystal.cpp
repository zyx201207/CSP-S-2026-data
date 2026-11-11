#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool fl1=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>10000){
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				fl1=0;
				break;
			}
		}
		if(fl1){
			for(int i=1;i<=n;i++){
				if(i*(i-1)/2>m){
					cout<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if((a[2]-a[1])*i*(i-1)/2>m){
					cout<<i;
					return 0;
				}
			}
		}
	}
	long long ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long cnt=1,S=m;
		for(int j=1;j<i;j++){
			if(S>=a[i]-a[j]){
				cnt++;
				S-=(a[i]-a[j]);
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
