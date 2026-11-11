#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

int a[200010];
string b[200010];
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
		sum+=a[i];
	}
	int ans=0;
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]) ans++;
	}
	cout<<ans;
	return 0;
} 
