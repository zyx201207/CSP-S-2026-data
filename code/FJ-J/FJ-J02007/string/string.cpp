#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[1000005];
char c[1000005];
int ans,l,r;
void f(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		cout<<a[i]<<" "<<c[i]<<"\n";
	}
	l=1,r=n;
	while(l<r){
		int nl=a[l];
		int nr=a[r];
		int now=min(nl,nr);
		if(c[l]!=c[r]){
			ans+=now;
//			cout<<ans<<" ; "<<now<<"\n";
		}
		a[l]-=now;
		a[r]-=now;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		
	}
	cout<<ans<<"\n";
}
signed main(){
//	freopen("string1.in","r",stdin);
//	freopen("string.out","w",stdout);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--)
	f();
	return 0;
}
