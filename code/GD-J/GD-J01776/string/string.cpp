#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s1="",c;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s1+=c;
		}
	}
	long long e=s1.size();
	for(long long i=0;i<=(e+1)/2-1;i++){
		if(s1[i]!=s1[e-i-1]){
			ans++;
		
		}
	}
	cout<<ans;
	return 0;
}
