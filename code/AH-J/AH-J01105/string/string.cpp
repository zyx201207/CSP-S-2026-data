#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long a[200005];
char b[200005];
string s;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);	
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		for(int i=1;i<=t;i++){
			s+=c;
		}
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]) ans++;
	}
	cout<<ans;

	return 0;
}
