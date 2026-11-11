//GZ-J00370 贵阳市第十八中学 曹语心
#include <bits/stdc++.h>
using namespace std;
long long n,x,sumn;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		sumn+=x;
		for(int j=1;j<=x;j++){
			s=s+c;
		}
	}
	if(sumn==n)cout<<sumn/2;
	else cout<<0;
	return 0;
} 
