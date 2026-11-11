#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	long long n,m=0,j=1;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		m+=a;
		while(a--){
			s[j]=c;
			j++;
		}
	}
	long long ans=0;
	for(long long l=1,r=m;l<=r;l++,r--){
		if(s[l]!=s[r])ans++;
	}
	cout<<ans;
	return 0;
}
