#include<bits/stdc++.h>
using namespace std;
#define int long long
struct zfc{
	int a;
	char ch;
}sz[200005];
string s="";
int n,a,ans,cnt;
char ch;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>sz[i].a>>sz[i].ch;
		cnt+=sz[i].a;
		for(int j=0; j<sz[i].a; ++j) s+=sz[i].ch;
	}
	int j=cnt-1;
	for(int i=0; i<cnt/2; ++i){
		if(s[i]!=s[j]) ans++;
		j--;
	}
	cout<<ans;
	return 0;
}

