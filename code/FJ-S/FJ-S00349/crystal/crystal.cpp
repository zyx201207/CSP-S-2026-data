#include<bits/stdc++.h>
using namespace std;
//CSPS RP++
#define int long long
const int MAXN=500005;
int n,m,a[MAXN],ans,mid,l;
bool B=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>1) l=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=l) B=0;
	}
	if(B){
		ans=1;
		for(int i=1;i<=n;i++){
			if(m>=i*l){
				ans++;
				m-=i*l;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int t=0,cnt=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]>m-t) break;
			t+=a[i]-a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
