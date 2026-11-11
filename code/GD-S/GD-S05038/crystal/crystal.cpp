#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10;

int n;
ll m,a[M];
int ans;

bool A=1;

bool B=1;
ll d;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
	}
	
	//AAAAAAA
	if(A){
	
	ans=1;
	for(ll i=1;;i++){
		if(ans==n){
			break;
		}
		if(m>=i){
			m-=i;
			ans++;
		}
		else {
			break;
		}
	}
	cout<<ans;
	return 0;
	
	}
	
	//BBBBBBBB
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(i==2){
			d=a[i]-a[i-1];
		}
		if(i>2){
			if(a[i]-a[i-1]!=d)B=0;
		}
	}
	
	if(B){
	
	ans=1;
	for(ll i=d;;i+=d){
		if(ans==n){
			break;
		}
		if(m>=i){
			m-=i;
			ans++;
		}
		else {
			break;
		}
	}
	cout<<ans;
	return 0;
	
	}
	
	for(int i=n;i>=2;i--){
		if(ans>=i){
			break;
		}
		ll lt=m;
		int r=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=lt){
				r++;
				lt-=a[i]-a[j];
			}
			else {
				break;
			}
		}
		ans=max(ans,r); 
	}
	cout<<ans;
} 
