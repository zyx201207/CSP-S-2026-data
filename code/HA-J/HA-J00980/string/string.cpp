#include<bits/stdc++.h>
using namespace std;
int n,a,le;
long long ans;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			le++;
		}
	}
	le--;
	for(int i=0;i<=le/2;i++){
		if(s[i]!=s[le-i]){
			ans++;
			s[le-i]=s[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
