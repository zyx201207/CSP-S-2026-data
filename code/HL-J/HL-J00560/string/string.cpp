#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		string c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long ans=1;
	for(long long i=s.size();i>=ans;i--){
		if(s[i-1]==s[ans-1]){
			ans++;
		}else{
			cnt++;
			ans++;
		}
	}
	cout<<cnt;
	return 0;	
}
