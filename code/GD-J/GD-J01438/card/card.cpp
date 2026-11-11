#include <bits/stdc++.h>
using namespace std;
int  MAXN=105;
long long a[105][105],g;
char n,m,z;
bool f; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int x,y;
	a[x][y]=='0';
	if(x==1||x==n||y==1||y==m) return false;
	if(a[x][y]=='0') return false;
	if(a[x][y]!='0') return true;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j) {
			cin>>a[i][j]>>a[x][y];
				g++;	
		}		

	cout<<g;
	return 0;
} 
