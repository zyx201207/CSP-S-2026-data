#include<bits/stdc++.h>
using namespace std;
int b[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,s=1; 
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=s;j<=s+a-1;j++){
			b[j]=c-'a'+1;
		}
		s+=a;
	}
	int ans=0;
	for(int i=1;i<=s/2;i++){
		if(b[i]!=b[s-i])ans++;
	}
	cout<<ans;
	return 0;
} 
