#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,x,f,q,b[200005],cnt;
string s[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n-a[i]+1<<" ";
	}
	return 0;
}