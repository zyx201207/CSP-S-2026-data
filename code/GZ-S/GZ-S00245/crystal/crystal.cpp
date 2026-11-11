//GZ-S00245 »ª÷ë Ñî³Ð½õ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll b[500005];
ll s[500005];//b[1]+...+b[i]
ll f[500005];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		s[i]=s[i-1]+b[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i;j>=1;j--){
			f[j]=f[j+1]+(s[i-1]-s[j-1]);
			if(f[j]<=m)ans=max(ans,i-j+1);
			if(f[j]>m)break;
		}
	}
	cout<<ans;
	return 0;
}

//Oct31==Dec25?
