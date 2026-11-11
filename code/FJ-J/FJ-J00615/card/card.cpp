#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5,max_m=3e5+5;
int n,m;
int a[max_n];
int ans[max_m];
int f[max_n],cnt[max_n];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=i;
	}
	
	return 0;
}


