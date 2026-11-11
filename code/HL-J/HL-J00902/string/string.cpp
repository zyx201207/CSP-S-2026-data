#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string in","r",stdin);
	freopen("string out","w",stdout);
	
	int n; cin>>n;
	int a,ans=0;
	string b,s;
	
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++) s+=b;
	}
	for(int i=0;i<=s.size()/2;i++){
		for(int j=s.size()-1;j>=s.size()/2;j--){
			if(s[i]==s[j]) continue;
			else{
				s[j]=s[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
