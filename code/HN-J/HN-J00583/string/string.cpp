#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
long long a[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l = 1,r = n;
	while(l<=r){
		if(a[l]<a[r]){
			long long k = min(a[l],a[r]);
			a[r]-=a[l];
			if(c[l]!=c[r]){
				ans+=k;
			}
			l++;
		}else{
			long long k = min(a[l],a[r]);
			a[l]-=a[r];
			if(c[l]!=c[r]){
				ans+=k;
			}
			r--;
		} 
	}
	cout<<ans;
	return 0;
}
