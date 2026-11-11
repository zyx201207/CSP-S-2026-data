#include<bits/stdc++.h>

using namespace std;
int n;
long long pos=0,ans=0;
char s[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s[++pos]=c;
		}
	}
	for(long long i=pos/2+pos%2;i<=pos;i++){
		if(s[i]!=s[pos-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
