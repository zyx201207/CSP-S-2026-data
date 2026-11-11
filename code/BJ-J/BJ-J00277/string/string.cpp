#include <bits/stdc++.h>
using namespace std;
string s,t;
long long x,n,ans;
char c;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
        cin>>x>>c;
        for(long long i=1;i<=x;i++) s=s+c;
	}
	long long l=s.size();
	for(long long i=0;i<l;i++){
        t=t+s[l-1-i];
	}
	for(long long i=0;i<l;i++){
        if(s[i]!=t[i]){
            ans++;
        }
	}
	cout<<ans/2;
	return 0;
}
