#include<bits/stdc++.h>
using namespace std;
string s,rs;
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--)s+=c;
	}
	rs=s;
	reverse(rs.begin(),rs.end());
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s[i]!=rs[i])ans++;
	}
	cout<<ans;
	
	return 0;
} 
