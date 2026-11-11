#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int a[N],ans,len;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s+=c[i];
		len+=a[i];
	}
	int l=0,r=len-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
