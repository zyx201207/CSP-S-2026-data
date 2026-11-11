#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char a[1234567];char k;
	long long n,b,c=0,ans=0;cin>>n;
	if(n==1){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b;cin>>k;
		for(int i=c;i<b+c;i++){
			a[i]=k;
		}c=strlen(a);
	}
    for(int i=c-1;i>=(c-1)/2;i--){
    	if(a[i]!=a[c-1-i])ans++;
	}
	if(ans<=c/2)cout<<ans;
	else cout<<c-ans;
	return 0;
}
