#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	int n,a,b=0;
	char c;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		b+=a;	
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<(s.size()/2);i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
