#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[300010],cnt;
int main(){ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			if(t[a[j]]==1) cnt++;
		}
	}
	return 0;
}
