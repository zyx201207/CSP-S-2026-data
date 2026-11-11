#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string s="";
int n;
ll ans,l;
struct str{
	int t;
	char ch;
}a[200010];
int main(){
	
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].ch;
	}
	bool tf=1,cf=1;
	for(int i=2;i<=n;i++){
		if(a[i].t!=a[i-1].t) tf=0;
		if(a[i].ch!=a[i-1].ch) cf=0;
	}
	if(cf){
		cout<<0;
		return 0;
	}
	if(tf){
		for(int i=1;i<=n;i++){
			s+=a[i].ch;
		}
		l=s.size();
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]) ans++;
		}
		cout<<ans*a[1].t;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].t;j++){
			s+=a[i].ch;
		}
	}
	l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;	
}