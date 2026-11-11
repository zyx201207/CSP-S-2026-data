#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
long long a[N];
char s[N];
string t="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>s[i]; 
		for(int j=1;j<=a[i];j++) t+=s[i];
	}
	int l=0,r=t.size()-1;
	long long ans=0;
	while(l<=r){
		if(t[l]!=t[r]) ans++;
		l++;
		r--;
	} 
	cout<<ans<<endl;
	return 0;
}


