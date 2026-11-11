#include<bits/stdc++.h>
using namespace std;
long long n;
string s,fs;
long long len=0;

long long ans;
long long dfs(long long de){

	if(fs==s){
		cout<<ans;
		return 0;
	}	
		char l=fs[len-1-de];
		s[de]=fs[de];
		fs[len-1-de]=fs[de];
		ans++;
		//cout<<fs<<" ";
		dfs(de+1);
		//fs[len-de-1]=l;
		//s[de]=l;
	}
	
	//return 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char c;
	
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(long long j=0;j<a;j++){
			s+=c;
		}
	}
	//cout<<s<<endl;
	//int j=0;
	for(long long i=len-1;i>=0;i--){
		fs+=s[i];
	}
	string ns=s;
	//cout<<fs;
	dfs(0);
	return 0;
}
