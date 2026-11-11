#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,m;
char s[999999999999999999999999];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			m++;
			s[m]=c;
		}
	}
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
