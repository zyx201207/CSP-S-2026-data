#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		char c;
		cin>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
		cnt+=x;
	}
	for(long long i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
