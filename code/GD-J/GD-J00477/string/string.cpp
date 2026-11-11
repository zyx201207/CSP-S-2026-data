#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],ans,l;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=" ";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=string(a[i],c[i]);
		l+=a[i];
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	} 
	cout<<ans;
	return 0;
}
