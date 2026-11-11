#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
string s="";
int n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}

