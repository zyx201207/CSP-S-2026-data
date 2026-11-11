#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char c[200010];
string s;
map<char,int> m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		m[c[i]]+=a[i];
	}
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else ans++; 
	}
	cout<<ans;
	return 0;
}
