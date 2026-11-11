#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		while(x--){
			s+=y;
			cnt++;
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
