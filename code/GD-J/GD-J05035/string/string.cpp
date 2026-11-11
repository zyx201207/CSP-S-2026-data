#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m;
string s="#";
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		int l;
		cin>>l>>x;
		string t="";
		for(int j=1;j<=l;j++) t=t+x+'#';
		s+=t;
	}
	long long mid=s.size()/2;
	long long l=mid,r=mid;
	while(l>=0&&r<s.size()){
		if(s[l]!=s[r]) ans++;
		l--;r++;
	}
	cout<<ans;
	return 0;
}
