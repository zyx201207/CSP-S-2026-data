#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int x[200005];
char y[200005];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(i==1||flag==0) continue;
		if(x[i]!=x[i-1]) flag=0;
	}
	int k=1;
	if(flag==1){
		k=x[1];
		for(int i=1;i<=n;i++) s[++cnt]=y[i];
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x[i];j++) s[++cnt]=y[i];
		}
	}
	int ans=0;
	for(int i=1;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i+1]) ans++;
	}
	cout<<ans*k;
	return 0;
}
