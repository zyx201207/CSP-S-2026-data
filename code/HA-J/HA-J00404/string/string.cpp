#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int j=1;j<=num;j++){
			s+=c;
		}
	}
	int ans=0,len=s.length();
	int l=0,r=s.length()-1;
	while(l!=r){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
