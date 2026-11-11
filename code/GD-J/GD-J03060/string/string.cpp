#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		string s1;
		int ans;
		cin>>ans;
		cin>>s1;
		for(int j=1;j<=ans;j++){
			s+=s1;
			cnt++;
		}	
	}
	int ans=0;
	int sl=s.size();
	int len=sl/2;
	string s2;
	for(int i=0;i<=len-1;i++){
		if(s[i]!=s[sl-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
