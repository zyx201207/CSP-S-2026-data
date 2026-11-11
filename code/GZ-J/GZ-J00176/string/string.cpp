//GZ-J00176遵义红花岗区第四小学娄雨涵 
#include<bits/stdc++.h>
#define int long long
using namespace std;
void abc(string x){
	int len=x.size(),ans=0;
	string l="",r="";
	if(len%2==0){
		for(int i=0;i<=(len-1)/2;i++){
			l+=x[i];
		}
		for(int i=len-1;i>=(len-1)/2;i--){
			r+=x[i];
		}
	}else{
		for(int i=0;i<=len/2-1;i++){
			l+=x[i];
		}
		for(int i=len;i>=(len)/2;i--){
			r+=x[i];
		}
	}
	//cout<<l<<endl;
	//cout<<r<<endl;
	bool f=0;
	for(int i=0;i<l.size();i++){
		if(l[i]!=r[i]){
			ans++;
		}else{
			f=1;
		}
	}
	if(f){
		cout<<ans;
	}else{
		cout<<len/2;
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="",x="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		if(a%2==0){
			for(int i=1;i<sqrt(a);i++){
				s+=c;
				s+=c;
			}
		}else{
			for(int i=1;i<a;i++){
				s+=c;
			}
		}
	}
	//cout<<s<<endl;
	abc(s);
	return 0;
}
