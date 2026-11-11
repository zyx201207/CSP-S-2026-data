#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,mx;
string s;
void solve(){
	if(1){
		for(int i=1;i<=n;i++){
			long long a;
			char b;
			cin>>a>>b;
			for(int j=1;j<=a;j++){
				s+=b;
			}
		}
		n=s.size();
		s=' '+s;
		for(int i=1;i<=n;i++){
			if(s[i]!=s[n+1-i])ans++;
		} 
		cout<<ans/2;
	}else{
		//;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	solve();
	
	return 0;
} 
