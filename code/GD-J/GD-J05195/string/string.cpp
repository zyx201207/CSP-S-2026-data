#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n,l=0,ans=0,cnt=1;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long ai;
		char ci;
		cin>>ai>>ci;
		for(long long j=cnt;j<=ai+cnt-1;j++){
			s[j]=ci;
		}
		l+=ai;
		cnt+=ai;
	}
	for(long long i=1;i<=(l+1)/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

