#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i]>>c[i];
	int l=1,r=n,ans=0;
	while(l<r){
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		if(a[l]<=a[r]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
