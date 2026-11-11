#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,half;
	long long len=0,cnt=0;
	string s="",sl="",sr="";
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;	
		for(int j=len;j<len+a[i];j++){
			s[j]=c;
		}
		len+=a[i];
	}
	if(len%2==0){
		half=len/2;
		for(int i=0;i<half;i++){
			sl[i]=s[i];
		}
		for(int i=half;i<len;i++){
			sr[i-half]=s[len-i+1];
		}
	}else{
		half=(len-1)/2;
		for(int i=0;i<half;i++){
			sl[i]=s[i];
		}
		for(int i=half+1;i<len;i++){
			sr[i-half-1]=s[i];
		}
	}
	for(int i=0;i<half;i++){
		if(sl[i]!=sr[half-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
