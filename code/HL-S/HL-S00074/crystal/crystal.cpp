#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,sum=0,b=1,x=1,ans=1,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z=a[i]-a[i-1];
		if(a[i]!=i){
			b=0;
		}
	}
	if(b==1){
		//dnegcha
		while(sum<=m){
			sum+=x;
			x++;
			ans++;
		}
		if(ans-1>n){
			cout<<n;
		}
		else{
			cout<<ans-1;
		}
		return 0;
	}
	else{
		while(sum<=m){
			sum+=z;
			z*2;
			ans++;
		}
		if(ans-1>n){
			cout<<n;
		}
		else{
			cout<<ans-1;
		}
	}
	return 0;
}
