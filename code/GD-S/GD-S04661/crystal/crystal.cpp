#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int kM = 5e5 + 10;

ll n,m,ans=1,t;
bool dc = true;
ll a[kM];

ll f(){
	int k = n-1;
	ll res=1,pm=m;
	for(int i=k-1;i>=0;i--){
		if(pm>=a[k]-a[i]){
			pm -= (a[k]-a[i]);
			res++;
		}
		else{
			break;
		}
	}
	return res;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			int kt = a[i]-a[i-1];
			if(i==1){
				t = kt;
			} 
			else{
				if(t != kt){
					dc = false;
				}
			}
		}
	}
	if(dc){
		cout<<f();
		return 0;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		ll nm = 1,km=m;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j] <= km){
				km -= (a[i]-a[j]);
				nm++;
			}
			else{
				break;
			}
		}
		ans = max(ans,nm);
	}
	cout<<ans;
	return 0;
} 
