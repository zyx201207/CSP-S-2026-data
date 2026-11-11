#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
char d;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>d;
		for(int i=1;i<=x;i++)s+=d;
	}
	for(int i=0;i<s.size()/2+1;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
			s[s.size()-i-1]=s[i];
		}
	}
	cout<<ans;
	return 0; 
}
