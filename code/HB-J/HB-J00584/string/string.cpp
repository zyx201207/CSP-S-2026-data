#include <bits/stdc++.h>
using namespace std;
int n,a,cnt=0,ans=0;
char c;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--) s1[cnt]=c,cnt++;
	}
	for(int i=0;i<=cnt/2;i++) if(s1[i]!=s1[cnt-1-i]) ans++;
	cout<<ans;
	return 0;
}
