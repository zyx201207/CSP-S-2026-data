#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt,ans;
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s[cnt++]=c;
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
