#include<iostream>
using namespace std;
signed main(){
	cin.tie(0);
	cout.tie(0);
	long long n,sum=0,ans=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	cin>>n;
	for(long long i = 0;i < n;i++){
		long long t;
		char s1;
		cin>>t>>s1;
		sum+=t;
		for(long long i = 0;i < t;i++){
			s+=s1;
		}
	}
	for(long long i = 1;i <= sum / 2;i++){
		if(s[sum/2-i] != s[sum/2+i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
