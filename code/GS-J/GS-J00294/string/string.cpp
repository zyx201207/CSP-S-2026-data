#include<bits/stdc++.h>
using namespace std;
long long n,m;
char a;
string s;
string s1;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	for(long long i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s==s1){
		cout<<0;
	}
	if(s!=s1){
		for(long long i=0;i<ceil(s.size()/2);i++){
			if(s[i]!=s1[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
