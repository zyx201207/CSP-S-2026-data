#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++) s+=c;
	}
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
