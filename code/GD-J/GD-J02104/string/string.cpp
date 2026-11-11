#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char c;
		cin>>m>>c;
		for(int j=1;j<=m;j++){
			s+=c;
		}
		cnt+=m;
	}
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
