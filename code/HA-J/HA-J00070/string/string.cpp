#include <bits/stdc++.h>
using namespace std;
long long x,n,ans;
struct node{
	long long a;
	char c;
}arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		for(long long j=1;j<=arr[i].a;j++){
			s+=arr[i].c;
			x++;
		}
	}
	for(long long i=1;i<=x;i++){
		if(i==x/2+1){
			break;
		}
		long long l=i-1,r=x-i;
		if(s[l]!=s[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
