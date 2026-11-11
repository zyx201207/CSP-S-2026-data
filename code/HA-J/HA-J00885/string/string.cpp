#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>c;
		for(int j=1;j<=a;++j){
			s+=c;
		}
	}
	s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s){
		cout<<'0';
		return 0;
	}else{
		for(int i=0;s.size();++i){
			if(s[i]!=s1[i]){
				ans++;	
			}
		}
		cout<<ans/2;
		return 0;
	}
} 
