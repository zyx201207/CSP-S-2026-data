#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll n,m,ans = -1e9;
void work(){
	ll b[500005];
	b[1] = 0;
	for(int i = 2;i<=n;i++){
		b[i] = a[i]-a[i-1];
	}
	for(int i = 1;i<=n;i++){
		b[i] = b[i-1]+b[i];
	}
	long long l = 1,r = 1;
	while(r<=n){
		if(b[r]-b[l]<m){
			r++;
			ans = max(ans,r-l+1);
		}
		else{
			l++;
		}
	}
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);//jidegaishuzu!!!!!! 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	work();
	cout<<ans-1;
	return 0;
} 
