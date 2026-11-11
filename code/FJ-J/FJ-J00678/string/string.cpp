#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long s[200005];
long long n,ans=0,r;
string z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		for(int j=1;j<=s[i];j++){
			z+=c[i];
		}
		
	}
	for(int i=0;i<=(z.size()/2);i++){
		if(z[i]!=z[z.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
