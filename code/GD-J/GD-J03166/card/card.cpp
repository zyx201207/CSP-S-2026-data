#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(m==1){
		cout<<1<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<n-b[i]<<' ';
	}
	return 0;
}
