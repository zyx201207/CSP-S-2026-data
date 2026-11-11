#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,l,l2,ans;
char c[N],c_s[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			s+=c[i];
		}
	}
	l=s.size(),l2=l;
	for(int i=0;i<=(l-1)/2;i++){
		c_s[i]=s[i];
	}
	if(l%2==0)l2=l+1;
	long long h=(l-1)/2;
	for(int i=(l2)/2;i<=l-1;i++){
		if(s[i]!=c_s[h])ans++;
		h--;
	}
	cout<<ans;
	return 0;
	
}
