#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	long long ans=0,cnt=0;
	int n,a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[++cnt]=c;
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i+1]) ans++; 
	}
	cout<<ans;
	return 0;
}

