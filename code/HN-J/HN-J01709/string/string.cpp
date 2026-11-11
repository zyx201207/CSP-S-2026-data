#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[200005];
long long sl[200005];
long long sr[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sl[i]=sl[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		sr[i]=sr[i+1]+a[i];
	}
	int l=1,r=n;
	long long now=0;
	while(l<=r){
		long long jump=min(sl[l],sr[r]);
		if(c[l]!=c[r]){
			ans+=jump-now;
			now=jump;
		}
		else{
			now=jump;
		}
		if(sl[l]<sr[r]){
			l++;
		}
		else if(sl[l]==sr[r]){
			l++,r--;
		}
		else{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
