//GZ-J00352 贵州省遵义市第四中学  罗永淇 
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		string a;
		cin>>k>>a;
		for(int j=1;j<=k;j++){
			s+=a;
		}
	}
	long long len=s.size();
	long long l=len/2;
	long long ans=0;
	for(long long i=0;i<l;i++){
		if(s[i]!=s[len-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
