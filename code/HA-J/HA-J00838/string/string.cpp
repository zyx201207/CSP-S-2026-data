#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char c[200005];
string s,s1,sq,s1q,sh,s1h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=(s.size()-1)/2;i++){
		sq+=s[i];
		s1q+=s1[i];
	}
	for(int i=s.size()/2;i<=s.size()-1;i++){
		sh+=s[i];
		s1h+=s1[i];
	}
	if(sh[0]==s1h[0]){
		for(int i=s.size()/2+1;i<=s.size()-1;i++){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=s.size()/2;i<=s.size()-1;i++){
		ans++;
	}
	cout<<ans;
	return 0;
}
