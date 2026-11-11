#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(string x){
	string t=x;
	reverse(t.begin(),t.end());
	return t==x;
}
int x[200009];
char y[200009];
int main(){
	freopen("string.in","r",stdin);
	feropen("string.out","w",stdout);
	int n,f=1;
	ll sum=0;
	cin>>n;
	string a;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(x[i]!=x[i-1]&&i!=1) f=0;
		sum+=x[i];
	}
	if(f==1){
		ll ans=0;
		int t=0;
		if(n%2==0) t=n/2;
		else t=n/2+1;
		for(int i=1;i<=t;i++){
			if(y[i]!=y[n-i+1]) ans+=x[i];
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x[i];j++){
				a+=y[i];
			}
		}
		if(check(a)){
			cout<<0;
			return 0;
		}
		int l=a.size(),s=0;
		if(l%2==0) s=l/2-1;
		else s=l/2;
		int cnt=0;
		for(int i=0;i<s;i++){
			if(a[i]==a[l-i-1]) continue;
			else cnt++; 
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
