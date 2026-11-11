#include<bits/stdc++.h>
using namespace std;
char b[200005];
string s;
long long a[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+b[i];
		}
	}
	for(int i=0;i<s.size()/2+1;i++){
		if(!(s[i]==s[s.size()-i-1])) ans++;
		//cout<<s[i]<<" "<<s.size()-i<<"\n";
	}
	cout<<ans;
	return 0;
}
