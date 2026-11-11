#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a;
	char c;
	string s1="",s2="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s1+=c;
		}
	}
	for(int i=s1.size()-1;i>=0;i--){
		s2+=s1[i];
	}
	int ans=0;
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s2[i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
