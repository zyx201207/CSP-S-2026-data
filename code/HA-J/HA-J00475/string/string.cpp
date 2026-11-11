#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char c[200005];
bool r=1;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	for(long long i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			r=0;
			ans++;
		}
	}
	if(r){
		cout<<"0";
	}else{
		cout<<ans;
	}
	return 0;
}
