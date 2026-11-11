#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l001[555555];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&l001[i]);
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,l001[i]);
		}
	}
	else if(m==n){
		ans=l001[0];
		for(int i=0;i<n;i++){
			ans&=l001[i];
		}
	}
	else{
		sort(l001,l001+n);
		ans=l001[n-1];
		for(int i=n-1;i>n-m;i++){
			ans&=l001[i];
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

