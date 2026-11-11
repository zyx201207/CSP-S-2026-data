#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a,l,ans;
string s,s1;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		while(a--){
			s1+=s;l++;
		}
	}
	for(int i=0;i<n+1/2;i++){
		if(s1[i]!=s1[l-i-1]){
			ans++;
			cout<<s1[i]<<" "<<s1[l-i-1]<<"\n";
		}
	}
	cout<<ans;
	return 0;
} 

