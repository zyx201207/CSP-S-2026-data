#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	string s="0";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	long long len=s.size()-1;
	for(long long i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 

