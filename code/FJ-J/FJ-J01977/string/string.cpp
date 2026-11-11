#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int n;
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1;
	int r=n;
	while(l<r){
		int num=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=num;
		}
		a[l]-=num;
		a[r]-=num;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

