#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,cnt=1;
string c,s[100007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s[cnt]=c;
			cnt++;
		}
	}
	for(long long i=cnt/2+1;i<cnt;i++){
		if(s[i]!=s[cnt/2-(i-cnt/2)])
			ans++;
	}
	cout<<ans;
	return 0;
}
