#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long L;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else{
			l++; r--;
		}
	}
	cout<<ans;
	return 0;
}
