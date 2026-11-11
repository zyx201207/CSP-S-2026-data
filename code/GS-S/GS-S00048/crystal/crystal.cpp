#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
typedef long long ll;
ll n,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];  
	}
	int ans=0;
	ll cnt=0;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=i+1;j>=1;j--){
			if(a[i]+a[j]+cnt>=m){
				ans=max(i,j-1);
				break;
			}
			cnt+=a[i]-a[j]+1;
		}
		ans++;
	}
	cout<<ans;
	return 0;
} 
