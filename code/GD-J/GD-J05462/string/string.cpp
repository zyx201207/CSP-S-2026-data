#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int ans=0;
	for(int i=0;i<=(l-1)/2;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
	}
	cout<<ans;
	
	
} 
