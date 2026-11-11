#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n;
int a[N];
char c[N];
string s;
int ans=0;
void check(){	
	int cnt=s.size()-1;
	for(int i=0;i<=s.size()/2-1;i++){
		int j=i+cnt;
		if(s[i]!=s[j]) ans++;
		cnt-=2;
		if(cnt<=0) break;
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	check();
	cout<<ans;
	return 0;
}
