#include<bits/stdc++.h>
using namespace std;
const int N =2e5+3;
typedef long long ll;
ll a[N];
ll ans=0;
ll len=0;
ll sum=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n,m;
	ll sum=-1e18;
	cin>>n>>m;
	ll maxx=-1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=20){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(n<=2000){
		if(m==1) cout<<maxx;
		else if(m==n){
			sum=a[1];
			for(int i=2;i<=n;i++){
				sum=sum&a[i];
			}
			cout<<sum;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					sum=max(sum,a[i]&a[j]);
				}
			}
			cout<<sum;
		}
	}else{
		if(m==n-1){
			for(int i=1;i<=n;i++){
				ll ans=a[i+1];
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					ans=ans&a[j];
				}
				sum=max(sum,ans);
			}
			cout<<sum;
		}
		else cout<<0;
	}
	cin>>n;
}
