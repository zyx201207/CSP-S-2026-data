#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	char c;
	long long n,a,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long l=s.size(),j;
	j=l-1;
	for(int i=0;i<=l/2-1;i++){
		if(s[i]!=s[j]){
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
} 
