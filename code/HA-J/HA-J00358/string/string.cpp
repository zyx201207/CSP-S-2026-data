#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	
	long long ans=0;
	long long len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-1-i]){
			s[i]=s[len-1-i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
