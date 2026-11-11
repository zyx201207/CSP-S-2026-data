#include<bits/stdc++.h>
using namespace std;
string s;
long long a[200100],n;
char c[200100];
int l,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		while(a[i]){
			s+=c[i];
			a[i]--;
		}
	}
	for(l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r])ans++;
	}
	cout<<ans;
	return 0;
}
