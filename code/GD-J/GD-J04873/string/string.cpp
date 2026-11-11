#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n;
	cin>>n;
	int cnt=0;
	long long a[n+10];
	char c[n+10];
	bool x=0;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(long long j=cnt;j<cnt+a[i];j++){
			s+=c[i];
			if(c[i]!=c[i-1]&&j>=2)x=1;
		}
		
		cnt+=a[i];
	}
	if(x==0){
		cout<<"0";
		return 0;
	}
	long long len=s.size()/2;
	long long ans=0;
	for(long long i=0;i<len;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
