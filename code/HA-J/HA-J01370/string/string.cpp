#include <bits/stdc++.h>
using namespace std;
const int N=2*10e5+5;
int ans=0;
int a;
char c;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>c;
		for (int j=0;j<a;j++){
			s+=c;
		}
	}
	int l=0,r=n+1;
	while (r>=0){
		t+=s[r];
		l++;
		r--;
	}
	int lenn=n/2;
	for (int i=lenn;i<n;i++){
		s[i]=t[i];
		ans++;
		
	}
	cout<<ans;
	return 0;
}
