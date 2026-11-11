#include<bits/stdc++.h>
using namespace std;
	string s;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	unsigned long long k=1,ans=0,i,n;
	cin>>n;
	for( i=0;i<n;i++){
	int a;
	char b;
	cin>>a>>b;
	for(unsigned long long j=k;j<k+a;j++){
		s[j]=b;
	}
	k+=a;
}	
k-=1;
		for( i=1;i<=k;i++){
		if(s[i]!=s[k+1-i])ans++;
	}
	cout<<ans/2;
	return 0; 
}
