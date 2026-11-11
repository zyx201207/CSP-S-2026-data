#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,ans=0;
	
	scanf("%lld",&n);
	string s="";
	vector<long long> a(n+1);
	vector<char> c(n+1);
	
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
		for(long long j=1;j<=a[i];j++) s+=c[i];
	}
	for(long long i=0;i<=s.size()/2-1;i++){
		if(s.size()%2==0){
			if(s[i]!=s[s.size()-1-i]) ans++;
		}
		else{
			if(s[i]!=s[s.size()-1-i]) ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
