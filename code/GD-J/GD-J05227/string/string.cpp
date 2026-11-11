#include<bits/stdc++.h>
using namespace std;
long long n,a[229028],ans;
char c[229028];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0;i<n;i++) for(int j=0;j<a[i];j++) s+=c[i];
	for(int i=0,j=s.size()-1;i<j;i++,j--) if(s[i]!=s[j]) ans++;
	cout<<ans; 
	return 0;
} 
