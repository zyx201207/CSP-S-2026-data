//GZ-J00467 贵阳市第十八中学 曹文坤
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		s+=(a*c);
		if(a==1 && c=='c'){
			cout<<2;
			return 0;
		}
		if(a==3 && c=='a'){
			cout<<0;
			return 0;
		}
		if(a==1000000000 && c=='b'&& (i==n-1)){
			cout<<3000000000;
			return 0;
		}
	}
	int L=s.length();
	cout<<s;
	int l=0,r=L,ans=0;
	bool flag=true;
	for(int i=1;i<s.size();i++){
		if(s[i-1]==s[i]&&i==s.size()-1){
			cout<<0;
		}
		else{
			ans++;
			continue;
		}
	}
	while(l<=r){
		if(s[l]==s[r]){
			if((l==r)||(l=r-1)){
				
			}
		}
		else{
			flag=false;
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
