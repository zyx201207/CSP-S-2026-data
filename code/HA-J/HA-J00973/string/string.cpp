#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],cnt,maxx,ans;
char c[200005],s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
		for(int j=1;j<=a[i];j++){
			s[++cnt]=c[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		if(s[i]!=s[cnt+1-i]){
			ans++;s[i]=s[cnt+1-i];
		}
	}
	cout<<ans;                         
	fclose(stdin);
	fclose(stdout);
	return 0;
}

