#include<bits/stdc++.h>
using namespace std;
long long n,a[200020];
string c[200020];
string s="",k="",d="";
long long bl=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=1;i<=n-1;i++){
		if(c[i]!=c[i+1]){
			bl==1;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(bl==0){
		cout<<0;
		return 0;
	}
	int m=s.size();
	for(int i=m;i>=0;i--){
		k+=s[i];
	}
	if(k==s){
		cout<<0;
		return 0;
	}else{
		for(int i=0;i<=m;i++){
			if(k[i]!=s[i]){
				ans++;
			}
		}
	}
	cout<<ans/2;
	return 0;
}
