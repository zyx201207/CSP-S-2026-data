#include<bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
int n;
ll m;
ll a[500005];
ll yu=0;
ll ans=0;
bool check(int use){
	if(a[n]-use<=yu){
		yu-=(a[n]-use);		
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	yu=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		if(check(a[i])){
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
