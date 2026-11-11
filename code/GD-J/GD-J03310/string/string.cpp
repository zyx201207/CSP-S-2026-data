#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		cnt+=a[i];
	}
	bool ok=1;
	for(int i=0;i<n-1;i++){
		if(b[i]!=b[i+1]){
			ok=0;
		}
	}
	if(ok){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
	
} 
