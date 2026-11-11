#include<bits/stdc++.h>
using namespace std;
long long n,l,r,a[10000001],ans;
char s[10000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1;r=n;
	while(l<r){
		if(s[l]==s[r]){
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
		}
		else{
			ans+=min(a[l],a[r]);
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
}
