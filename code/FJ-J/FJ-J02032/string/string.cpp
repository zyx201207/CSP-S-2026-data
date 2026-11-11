#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n;
deque<ll> a;
deque<char> b;
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	ll cnt=0;
	char lst;
	cin>>cnt>>lst;
	for(ll i=2;i<=n;i++){
		int ai;
		char ci;
		cin>>ai>>ci;
		if(ci==lst){
			cnt+=ai;
		}else{
			a.push_back(cnt);
			b.push_back(lst);
			lst=ci;
			cnt=ai;
		}
	}
	a.push_back(cnt);
	b.push_back(lst);
	int i=0, j=a.size()-1;
	cnt=0;
	ll ans=0;
	while(i<j){
		if(a[i]>a[j]){
			if(b[i]!=b[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}else if(a[i]<a[j]){
			if(b[i]!=b[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}else{
			if(b[i]!=b[j]){
				ans+=a[j];
			}
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
} 
