//GZ-J00162 遵义市第十二中学 田家锜 
#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s=s+y;
		}
	}
	string b=s;
	reverse(b.begin(),b.end());
	long long len=s.size();
	long long ans=0;
	for(int i=0;i<len;i++){
		if(s[i]!=b[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
