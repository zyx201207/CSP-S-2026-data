#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
string s,fs;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t;
	char a;
	for(int i=1;i<=n;i++){
		cin>>t>>a;
		for(int j=1;j<=t;j++){
			s+=a;
		}
	}
	int len=s.size();
	for(int i=len-1;i>=0;i--){
		fs[i]=s[len-1-i];
	}
	for(int i=0;i<len;i++){
		if(s[i]==fs[i]){
			cnt=0;
		}else{
			cnt=1;
			break;
		}
	}
	if(cnt==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<len;i++){
		if(s[i]!=fs[i]){
			fs[i]=s[i];
			s[len-i-1]=fs[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
