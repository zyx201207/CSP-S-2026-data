#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char x;
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s+=x;
		}
	}
	long long ans=0;
	for(int i=0;i<s.size();i++){
		for(int j=s.size();j>=i;j--){
			if(s[i]!=s[j]&&i+j==s.size()){
				ans++;
			}
		}
	
	}
	cout<<ans;
	return 0;
}
