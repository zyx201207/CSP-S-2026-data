#include<bits/stdc++.h>
using namespace std;
int const N=1e9+5;
char s[N]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=1,len=0;
	cin>>n;
	char c;
	long long a;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(long long j=0;j<a;j++){
			s[x]=c;
			x++;
		}
	}
	long long ans=0;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
