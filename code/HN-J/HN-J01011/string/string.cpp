#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],len,ans;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int k=a[1];
	for(int i=2;i<=n;i++) k=__gcd(k,a[i]);
	for(int i=1;i<=n;i++) a[i]/=k,len+=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
//	cout<<s<<"\n";
	int l=0,r=len-1;
	while(l<r){
//		cout<<l<<" "<<r<<"\n"; 
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans*k;
	return 0;
}

