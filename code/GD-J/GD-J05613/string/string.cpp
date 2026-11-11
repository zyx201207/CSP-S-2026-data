#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005],d[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ip=0;
	cin>>n;
	ll sum=0;
	string s="";
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	ll cnt=0,mid=(sum+1)/2-1;
	for(int i=0;i<=mid;i++){
		if(s[i]!=s[sum-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}

