#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a,mid,l,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	l=s.size();
	s=' '+s;
	mid=(l+1)/2+1;
	for(int i=mid;i<=l;i++){
		if(s[i-mid+1]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}
