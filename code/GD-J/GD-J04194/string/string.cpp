#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,a[N],ans;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
//		scanf("%c",&b[i]);
		cin>>b[i]; 
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(b[l]!=b[r])ans+=a[l];
			a[l]=a[r]=0;
			++l,--r;
		}
		else if(a[l]<a[r]){//小在前 
			if(b[l]!=b[r])ans+=a[l];
			a[r]-=a[l];	
			a[l]=0;
			++l;
		}
		else{//小在后 a[l]>a[r]
			if(b[l]!=b[r])ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			--r;
		}
	}
	//处理单个，但一样啊 
	cout<<ans;
	return 0;
}
