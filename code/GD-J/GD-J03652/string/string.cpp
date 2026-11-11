#include <bits/stdc++.h>
using namespace std;
int n,a[200005],l=0,r,ans;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		int x=a[i];
		while(x--){
			s+=c[i];
		}
	}
	r = s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
}
