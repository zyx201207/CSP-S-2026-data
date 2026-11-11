#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void fun(string& s,int n,char c){
	char *cstr=new char[n];
	
	for(int i=0;i<n;i++){
		cstr[i]=c;
	}
	cstr[n]='\0';
	s=s+string(cstr);
	delete[] cstr;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;cin>>n;string s;
	for(int i=1;i<=n;i++){
		int t;char u;cin>>t>>u;
		fun(s,t,u);
	}
	const size_t size=s.length()-1;
	int ans=0;
	for(size_t i=0;i<=size/2;i++){
		if(s[i]!=s[size-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
