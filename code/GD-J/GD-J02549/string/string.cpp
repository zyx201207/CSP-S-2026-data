#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	string str;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long len;
		char str1;
		cin>>len>>str1;
		for(long long j=1;j<=len;j++){
			str+=str1;
		}
	}
	for(long long i=0;i<str.size()/2;i++){
		if(str[i]!=str[str.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
