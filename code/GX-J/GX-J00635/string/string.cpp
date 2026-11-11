#include <bits/stdc++.h>
using namespace std;
const int N=1e9;
long long int T,a,k,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>c;
		for(long long int i=k;i<=k+a-1;i++){
			s[i]=c;
		}
		k=k+a;
	}
	int t=0;
	for(long long int j=k-1;j>=0;j--){
		if(s[t]!=s[j])ans++;
		t++;
	}
	cout<<ans/2;
	return 0;
}
