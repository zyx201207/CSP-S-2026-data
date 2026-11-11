#include<bits/stdc++.h>
using namespace std;
int n,a[200010],l,r;
long long ans;
char b[200010];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	l=1;r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];r--;
			}else{
				l++;r--;
			}
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]<a[r]){
				a[r]-=a[l];l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];r--;
			}else{
				l++;r--;
			}
		}
	}
	cout<<ans;
	
	return 0;
}