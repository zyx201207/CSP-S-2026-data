#include <bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	bool b=1;
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]) b=0;
	}
	if(b){
		cout<<cnt;
		return 0;
	}
	int ans=0;
	n+=1;
	for(int i=n/2;i>=1;i--){
		if(a[i]!=a[n-i]&&c[i]==c[n-i]){
			cnt+=abs(a[i]-a[n-i])-ans;
			ans=abs(a[i]-a[n-i])-ans;
		}
		if(c[i]!=c[n-i]){
			cnt+=min(a[i],a[n-i])-ans;
			ans=0-abs(a[i]-a[n-i]);
		}
	}
	cout<<cnt+1;
	return 0;
}
