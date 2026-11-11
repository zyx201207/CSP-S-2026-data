#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt=0;
	string s="";
	string c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<=a/10+a%10-10;j++){
			s+=c;
			s+=c;
			s+=c;
			s+=c;
			s+=c;
			s+=c;
			s+=c;
			s+=c;
			s+=c;
			s+=c;
		}
		for(int j=1;j<=a%10;j++){
			s+=c;
		}
	}
	long long len=s.size()-1;
	if(len%2==0){
		for(int i=0;i<=len/2;i++){
			if(s[i]!=s[len-i]){
				cnt++;
	 	}
		}
	}
	else{
		for(int i=0;i<=len/2;i++){
			if(s[i]!=s[len-i]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
