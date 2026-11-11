#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,len;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
		len+=x;
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
