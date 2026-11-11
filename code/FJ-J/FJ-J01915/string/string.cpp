#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a[200005],sum,ans;
char c[200005];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	ll l=1,r=n;
	
	while(l<r){
		
		if(c[l]!=c[r]){//如果这两个字母不一样 
			
			if(a[l] > a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l] < a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{//如果个数相等
				ans += a[l];
				l++;
				r--;
			}
		}else{//如果这两个字母一样 
			if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}else if(a[l] > a[r]){
				a[l] -= a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
