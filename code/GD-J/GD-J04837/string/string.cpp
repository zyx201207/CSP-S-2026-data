#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		int hc=0;
		char kk;
		cin>>hc>>kk;
		for(int j=1;j<=hc;j++){
			s+=kk;
		}
	}
	int ans=0;
	n=s.size();
//	for(int i=0;i<n;i++){
//		s2[i]=s[n-i-1];
//	}
//	cout<<s<<endl;
	for(int i=0;i<=n/2;i++){
		if(s[i]!=s[n-i-1]){
			ans++;
//			cout<<n-1-i;
//			cout<<ans<<" ";
		}
	}
	cout<<ans;
	return 0;
} 
