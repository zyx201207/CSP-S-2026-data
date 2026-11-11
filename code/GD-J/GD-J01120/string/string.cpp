#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	long long ans=0;
	for(long long i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
