#include<bits/stdc++.h>
using namespace std;
string s;
long long x,a,ans;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>x;
	while(x--){
		cin>>a>>b;
		for(int i=1;i<=a;i++){                
			s+=b; 
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans; 
}
