#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
string s;
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char op; 
		cin>>x>>op;
		cnt+=x;
		for(long long j=1;j<=x;j++)
			s+=op;
	}
	for(long long i=0;i<cnt;i++){
		if(s[i]!=s[cnt-i-1]){
			flag=false;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	string a=s.substr(0,cnt/2);
	string b=s.substr(cnt/2+1,cnt-1);
	for(long long i=0;i<cnt/2;i++){
		if(a[i]!=b[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
