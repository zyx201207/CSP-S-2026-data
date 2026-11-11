#include<bits/stdc++.h>
using namespace std;
string s=" ";
int n,len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		len+=t;
		for(int j=1;j<=t;j++){
			s+=c;
		}
	}
	if(len%2==0){
		int cnt=0;
		for(int i=1;i<=len/2;i++){
			int j=i+len/2;
			if(s[i]!=s[j]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}else{
		int cnt=0;
		for(int i=1;i<=len/2;i++){
			int j=i+len/2+1;
			if(s[i]!=s[j]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
