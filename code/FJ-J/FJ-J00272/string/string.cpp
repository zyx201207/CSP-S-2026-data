#include<bits/stdc++.h>
using namespace std;
int n,a[200010],cnt,len,mon;
string s;
char b[200010];
bool isstr(string c,int ls){
	if(ls%2==0){
		for(int p=0;p<ls/2;p++){
			if(c[ls/2-p-1]!=c[ls/2+1+p-1]){
				return false;
			}
		}
		return true;
	}else{
		for(int p=0;p<ls/2;p++){
			if(c[ls/2-p-1]!=c[ls/2+2+p-1]){
				return false;
			}
		}
		return true;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	if(isstr(s,len)){
		cout<<0;
		return 0;
	}
	if(len%2==0){
		mon=len/2-1;
	}else{
		mon=len/2;
	}
	for(int i=len-1;i>mon;i--){
		if(s[i]!=s[i-mon-1]){
			s[i]=s[i-mon-1];
			cnt++;
		}
		if(isstr(s,len)){
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
