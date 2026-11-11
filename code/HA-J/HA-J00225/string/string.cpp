#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s=" ";
	int n;
	long long l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		l+=a;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
} 



