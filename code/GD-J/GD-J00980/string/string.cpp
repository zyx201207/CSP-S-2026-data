#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<char>b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	ll ans=0;
	while(l<=r){
		if(b[l]!=b[r]){
			int x=min(a[l],a[r]);
			ans+=x;
			a[l]-=x;a[r]-=x;
		} 
		else{
			int x=min(a[l],a[r]);
			a[l]-=x;a[r]-=x;
		}
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout<<ans;
	return 0;
}
