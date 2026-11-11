#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,a1=0,ans=0;
	char c;
	cin>>n;	
	while(n--){
		cin>>a>>c;	
		while(a--){
			s+=c;
		}	
	}
	
	int l=0,r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
