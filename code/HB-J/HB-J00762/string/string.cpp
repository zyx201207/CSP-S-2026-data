#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	int t;
	long long l=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		char c;
		cin>>n>>c;
		l+=n;
		for(int j=1;j<=n;j++){
			S+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<l;i++){
		if(S[i]!=S[l-i-1])ans++;
	}
	cout<<(long long)(ans/2);
	return 0;
}
