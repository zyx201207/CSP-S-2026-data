#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
string s;
bool hw(string x){
	bool r=1;
	for(int i=0;i<=x.length()/2;i++){
		if(x[i]!=x[x.length()+1-i]){
			r=0;
		}
	}
	return r;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]) cout<<0;
		else cout<<min(a[1],a[2]);
		return 0;
	}int r=1;
	for(int i=1;i<=n;i++){
		if(c[i]!=c[1]){
			r=0;
		}
	}if(r==1) cout<<0;return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]; 
	}cout<<ans/2;
	return 0;
}
