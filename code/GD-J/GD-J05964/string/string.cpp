#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int m;
		char a;
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	string rs=s;
	int ans=0;
	reverse(s.begin(),s.end());

	
	for(int i=0;i<s.length()/2+s.length()%2;i++){
		if(rs[i]!=s[i]){
			ans++;

		}
		
	}
	cout<<ans;
	return 0;
} 
