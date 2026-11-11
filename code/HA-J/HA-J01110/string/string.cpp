#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>cnt>>t;
    	for(int j=1;j<=cnt;j++){
    		s+=t;
		}
	}
	long long l=s.size();
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
