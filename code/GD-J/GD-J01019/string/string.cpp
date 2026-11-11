#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int l=0;
	string s=" ";
	for(int i=1;i<=n;i++){
		char c;
		int x;
		cin>>x>>c;
		l+=x;
		for(int i=1;i<=x;i++){
			s=s+c;
		}
	}
	int mid=(l+1)/2;
	for(int i=1;i<=mid;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//56
