#include<bits/stdc++.h>
using namespace std;
int t,n[1000005],ans,v;
char c[1000005];
string s;
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	int f=0;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>c[i];
		if(n[i]!=n[1]){
			f=1;
		}
	}
	if(f==0){
		v=n[1];
		for(int i=1;i<=t;i++){
			n[i]=1;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			s=s+c[i]; 
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	if(f==0){
		ans*=v;
	}
	cout<<ans;
	return 0;
}


