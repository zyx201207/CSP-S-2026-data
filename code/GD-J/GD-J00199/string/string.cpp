#include<bits/stdc++.h>
using namespace std;
long long n,b[200003],x=0,ans=0;
char a[200003],s[1000002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		for(int j=1;j<=b[i];j++){
			x++;s[x]=a[i];
		}
	}
	for(int i=1;i<=x/2;i++){
		if(s[i]!=s[x-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
