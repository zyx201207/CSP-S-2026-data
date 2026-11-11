#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s[l+i]=c;
		}
		l+=a;
	}
	int ans=0;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
