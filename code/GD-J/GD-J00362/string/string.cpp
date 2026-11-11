#include<bits/stdc++.h>
using namespace std;
string s,b;
long long n,m,w;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m;
		cin>>b;
		for(long long j=1;j<=m;j++){
			s+=b;
		}
	}

	for(long long i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) w++;
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
