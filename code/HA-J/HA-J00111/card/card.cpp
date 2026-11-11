#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],b[10000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		b[a[j]]++;
	}
}   
    for(int i=1;i<=m;i++){
    	if(b[i]==0) continue;
		cout<<b[i]<<" ";
	}
	return 0;
	
}
