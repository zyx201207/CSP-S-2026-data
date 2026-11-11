//GZ-J00276 »ÆÈË÷ë 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,ans,x,y,L;
string s;
pair<int,char> a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1) return cout<<0,0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		L+=a[i].first;
		for(int j=1;j<=a[i].first;j++) s+=a[i].second;
	}
	s=" "+s;
	int len=L/2;
	for(int i=1,j=L;i<=len;i++,j--) ans+=(s[i]!=s[j]);
	cout<<ans;
	return 0;
}

