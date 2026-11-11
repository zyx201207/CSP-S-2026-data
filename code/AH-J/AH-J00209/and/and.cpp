#include<bits/stdc++.h>
using namespace std;
int n,a,s[200005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		maxn=max(maxn,s[i]);
	}cout<<maxn;
}
