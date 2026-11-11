#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
string s;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n<=100000){
    for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else {
			ans++;
		}
	}
	cout<<ans;
    }
    else {
		map <long long,char> ss;
		long long now=0;
		for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			now++;
			ss[now]=c;
		}
	}
	for(long long i=1;i<=now/2;i++){
		if(ss[i]==ss[s.size()-i+1]) continue;
		else {
			ans++;
		}
	}
	cout<<ans;
	}
    return 0;
}