#include<bits/stdc++.h>

using namespace std; 
typedef long long ll;
const ll N =5e5+10;
ll n, m, ans, a[N], b, d;
bool A=true, B;
void check(ll x){
	
	bool f=true;
	ll sum=m, s=0;
	for(ll i=x; i >= 1&&f; --i){
		if(sum >= (a[x]-a[i])){
			s++;
			sum -= (a[x]-a[i]);
		}else f=false;
	}
	ans=max(ans,s);
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	if(m==0){
		cout<<1; return 0;
	}
	for(ll i=1; i <= n; ++i){
		cin >> a[i];
		if(a[i]!=i) A=false;

		if(i==2){
			B=true;
			d=a[i]-a[i-1];
		}else if(i>2&&a[i]-a[i-1]!=d){
			B=false;
		}
		
	}

	if(A){
		//cout<<'a';
		for(ll i=2; i <= n+1; ++i){
			b += (i-1)*(i-1);
			if(m < b){
				ans=i-1; break;
			}
		}	
		cout<<ans;
		return 0;
	}else if(B){
		//cout<<"b";
		b=0;
		for(ll i=2; i <= n+1; ++i){
			b += (i-1)*d;
			if(m < b){
				ans=i-1; break;
			}
		}	
		cout<<ans;
		return 0;
	}
	
	
	sort(a+1,a+n+1);
	
	for(ll i=n; i>=1; --i){
		if(i < ans) break;
		check(i); 
	}
	
	cout<<ans;
	return 0;
	

}
