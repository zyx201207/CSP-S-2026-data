#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long ans;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long shu;
		cin>>shu;
		char c;
		cin>>c;
		for(long long jk=0;jk<shu;jk++){
			s+=c;
		}
		
	}
	
	long long len=s.size();
	long long jb=0;
	for(long long i=len-1;i>=0;i--){
		
		if(s[jb]!=s[i]){
			ans++;
		}
		jb++;
	}


	cout<<ans/2;
	return 0;
}
//Trick||Treat!
