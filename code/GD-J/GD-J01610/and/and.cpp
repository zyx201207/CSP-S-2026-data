#include<bits/stdc++.h>
using namespace std;
string a[200010];
char d[10000100],e[10000100];
int b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(m==1)c=max(c,b[i]);
	}
	if(m==1)cout<<c;
	return 0;
}
