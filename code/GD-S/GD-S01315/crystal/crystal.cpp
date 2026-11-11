#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> a(1,0);
vector<vector<ll>> c(1,vector<ll>(1,0));
bool A=true,B=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m,ai,dc;
	cin>>n>>m;
	if(n<5){
		A=false;
		B=false;
	}
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
		if(ai!=i+1&&A)A=false;
		if(i>1&&ai-a[i-1]!=dc&&B)B=false;
		if(i==1){
			dc=a[i]-a[0];
		}
	}
	if(A){
		ll res=1,i=1;
		while(m>0){
			m-=i;
			if(m>=0){
				res++;
			}
			i++;
		}
		cout<<res;
		return 0;
	}
	if(B){
		ll res=1,i=dc;
		while(m>0){
			m-=i;
			if(m>=0){
				res++;
			}
			i+=dc;
		}
		cout<<res;
		return 0;
	}
	sort(a.begin()+1,a.end());
	ll sum=0,r=1,re=0;
	c.assign(n+1,vector<ll>(1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ll chazhi=a[i]-a[j];
			c[i].push_back(chazhi);
		}
		sort(c[i].begin()+1,c[i].end());
	}
	//cout<<1<<endl;
	for(int i=n;i>0;i--){
		r=1;
		for(int j=1;j<=i;j++){
			sum+=c[i][j];
			if(sum>m){
				sum=0;
				break;
			}else{
				r++;
			}
		}
		re=max(re,r);
	}
	cout<<re;
	return 0;
} 
