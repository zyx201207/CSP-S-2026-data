#include<bits/stdc++.h>
using namespace std;
long long n,c[200009],ans;
char s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>s[i];
	}
	int k=1;
	while(n>k){
		if(s[k]!=s[n]){
			ans+=min(c[n],c[k]);
		}
		long long aa=min(c[n],c[k]);
		c[n]-=aa;
		c[k]-=aa;
		if(c[n]==0)n--;
		if(c[k]==0)k++;
	}
	cout<<ans;
	return 0;
}
