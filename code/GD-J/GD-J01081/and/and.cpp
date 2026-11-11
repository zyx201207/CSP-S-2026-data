#include<bits/stdc++.h>
using namespace std;
int n,m,ar[500010],t[300010],tt[300010],ttt[300010];
long long s,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}sort(ar+1,ar+1+n,greater<int>()); 
	cout<<ar[m];
	return 0;
} 
