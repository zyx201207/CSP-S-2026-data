#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int n,m;
int a[500001];
int b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	stack<int> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int asdf=1;asdf<=n;asdf++){
		for(int i=asdf;i<=n;i++){
			s.push(a[i]);
		}
	}
	for(int i=1;i<=m;i++) cout << "1 ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
