#include<bits/stdc++.h>
using namespace std;
long long n,m,h,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		h+=m;
		for(int j=1;j<=m;j++){
			s+=c;
		}
	}
	for(int i=0;i<h/2;i++){
		if(s[i]!=s[h-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
