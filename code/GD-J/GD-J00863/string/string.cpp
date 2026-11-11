#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
ll s[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	ll len;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ml=1,mr=s[n];
	ll cnt=0;
	while(l<r){
		if(c[l]==c[r]){
			ml++;mr--;
			if(ml>s[l])l++;
			if(mr>s[r-2]&&mr<=s[r-1])r--;
		}
		else {
			cnt++;
			ml++;mr--;
			if(ml>s[l])l++;
			if(mr>s[r-2]&&mr<=s[r-1])r--;
		}
	}
	cout<<cnt;
	return 0;
}
