#include<bits/stdc++.h>
using namespace std;
long long n,t,cnt,ans;
string s;
char c;
int main(){
	freopen("string.in","t",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>t>>c;
		for(int j=1;j<=t;j++){
			s[cnt++]=c;
		}
	}
	cnt--;
	for(long long i=0;i<=cnt/2;i++){
		ans+=!(s[i]==s[cnt-i]);
	}
	cout<<ans;
	return 0;
}
