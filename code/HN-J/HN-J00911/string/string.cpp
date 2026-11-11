#include<bits/stdc++.h>
using namespace std;
int n,ans;
int l[20005],j;
char g[20005];
string s,a;
int ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>l[n]>>g[n];
		for(int i=0;i<n;i++)for(j;j>=0;j--)s[i*j]=g[i];
	}
	ll=s.size()/2;
	if(s.size()/2!=0)ll++;
	for(int i=0;i<ll;i++)a[i]=s[i];
	for(int i=ll;i>0;i--)a[i+ll]=s[i];
	for(int i=0;i<a.size();i++)if(a[i]!=s[i])ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

