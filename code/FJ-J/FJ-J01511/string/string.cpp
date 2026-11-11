#include <bits/stdc++.h>
using namespace std;
int a,n,ans,t[30],tmp;
string s;
string r;
char c;
long long cnt;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		t[c-'a'+1]++;
		if(i!=1 && a!=tmp){
			f=0;
		}
		tmp=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=1;i<=26;i++){
		if(t[i]>0){
			cnt++;
		}
	}
	if(f){
		cout<<tmp*(n/cnt);
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(s[i]!=s[n-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
