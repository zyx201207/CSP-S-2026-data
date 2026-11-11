#include<bits/stdc++.h>
using namespace std;
string s;
long long p,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char c;
		cin>>m>>c;
		for(int i=1;i<=m;i++){
			s[++p]=c;
		}
	}
	for(int i=1;i<=p/2;i++){
		if(s[i]!=s[p-i]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
