#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		string a;
		cin>>x>>a;
		for(long long i=1;i<=x;i++){
			s+=a;
		}
	}
	long long l=s.size();
	long long j=l-1;
	long long ans=0;
	for(long long i=0;i<l;i++){
		if(s[i]!=s[j]){
			s[j]=s[i];
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}
