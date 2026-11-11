#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,cnt=0,ans=0;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		char c;
		long long a;
		cnt+=a;
		cin>>a>>c;
		for(long long j=1;j<=a;j++) s+=c;
	}
		for(long long i=0,j=cnt-1;(j>=cnt/2)&&(i<=cnt/2);i++,j--){
			if(s[i]!=s[j]) ans++;
		}
	cout<<ans;
	return 0;
}
