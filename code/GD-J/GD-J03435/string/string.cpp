#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s;
bool hw(long long x){
	if (s[x]==s[cnt-1-x]) {
		return true;
	}
	return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=0;i<n;i++){
		long long a;char c;
		cin>>a>>c;
		while (a--){	
			s[cnt]=c;
			cnt++;
		}
	}
	long long ans=0;
	for (long long i=0;i<(cnt+1)/2;i++){
		if(!hw(i)) ans++;
	}
	cout<<ans;
}
