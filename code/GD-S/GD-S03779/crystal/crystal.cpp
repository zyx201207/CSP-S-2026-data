#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll a[N],nums;
ll n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1;
	while(l<=r and r<=n and l<=n){
//		cout<<l<<" "<<r<<" "<<nums<<endl;
		if(l==r){
			r++;
			nums=a[r]-a[l];
		}
		else{
			if(nums==m){
				
				ans=max(ans,r-l+1);
				r++;
				nums+=(a[r]-a[r-1])*(r-l);
//				nums-=(a[r]-a[l]);
//				l++;
			}
			if(nums>m){
				nums-=(a[r]-a[l]);
				l++;
			}
			if(nums<m){
				r++;
				nums+=(a[r]-a[r-1])*(r-l);
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
} 
