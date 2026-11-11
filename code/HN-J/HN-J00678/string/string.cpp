#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len;
string s;
bool check(int k){
	int l=0,r=len-1,ans=0;
	while(l+1<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	return ans<=k;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		len+=x;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	int l=-1,r=len+1;
	while(l+1!=r){
		int mid=(l+r)/2;
		if(check(mid)==true){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<r;
	return 0;
}
