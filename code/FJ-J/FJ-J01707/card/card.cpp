#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],c[200010],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==a[i-1]){
			c[k]++;
		}
		else{
			c[++k]++
		}
	}
	for(int i=1;i<=m;++i){
		cout<<c[i]<<" ";
	}
	return 0;
}
