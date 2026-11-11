#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int a,l;
	char c; 
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=l-1;i>=0;i--){
		t+=s[i];
	}
	if(s==t){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0;i<l/2;i++){
			if(s[i]!=t[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
