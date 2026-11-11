#include <bits/stdc++.h>
using namespace std;
int n;
string s; 
long long ans,tot;
int main(){
	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long t1;
		char t2;
		cin>>t1>>t2;
		for(long long i=1;i<=t1;i++) s+=t2;
		tot+=t1;
	}
	for(long long i=tot-1;i>=tot/2;i--){
		if(s[i]!=s[tot-i-1]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
