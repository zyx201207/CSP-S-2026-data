#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			int p=min(a[l],a[r]);
			a[l]-=p;
			a[r]-=p;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}else{
			int p=min(a[l],a[r]);
			a[l]-=p;
			a[r]-=p;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
			ans+=p;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
