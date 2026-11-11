#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,sum=-1;
ll a[500005];
ll ans[10004][10004];
ll t[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	ll kkkk=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]==a[i-1]-a[i-2])kkkk++;
	}
	if(kkkk==n-1){
		kkkk=0;
		ll dif=abs(a[n]-a[n-1]);
		if(dif==0)cout<<n;
		else{
			for(int i=1;i<=n;i++){
				if(kkkk>=m){
					cout<<i<<endl;
					return 0;
				}else kkkk+=i*dif;
			}
			cout<<n<<endl;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			t[j]=a[i]-a[j];
		}
		for(int j=1;j<i;j++){
			ans[i][j]=ans[i][j-1]+t[j]; 
		}
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			ll v=ans[r][r-1]-ans[r][l-1];
			if(v<=m){
				if(r-l+1>sum){
					sum=r-l+1;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

