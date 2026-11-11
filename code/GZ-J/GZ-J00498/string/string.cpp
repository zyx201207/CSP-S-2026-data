//GZ-J00498 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;cin>>x;
		char c;
		cin>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	for(long long i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
