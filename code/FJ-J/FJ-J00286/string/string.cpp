#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",c;
	long long n,ans=0;
	cin>>n;
	long long a;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long len=s.size(),k=len-1;
	for(int i=0;i<len/2;i++){
		if(i>=k){
			break;
		}
		if(s[i]==s[k]){
			continue;
		}
		else{
			ans++;
		}
		k--;
	}
	cout<<ans;
	return 0;
}
