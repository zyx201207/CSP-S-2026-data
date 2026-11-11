#include<bits/stdc++.h>
using namespace std;
int n;
long long c=0,ans=0;
long long a[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];char b;
		cin>>b;
		c+=a[i];
		for(int j=1;j<=a[i];j++){
			s=s+b;
		}
	}
	long long mid=(c+1)/2-1;
	for(int i=0;i<=mid;i++){
		if(s[i]!=s[c-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
