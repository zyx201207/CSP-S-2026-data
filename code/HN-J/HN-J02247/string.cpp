#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],p=1,q,m=1;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i] >>c;
		for(int j=m;j<=m+a[i]-1;j++){
			s[j]=c;
		}
		m=m+a[i];
	}
	while(p*p<m){
		if(s[p]!=s[m-p-1]){
			q=q+a[p];
		}
		p=p+a[p];
	}
	cout <<q;
	return 0;
} 
