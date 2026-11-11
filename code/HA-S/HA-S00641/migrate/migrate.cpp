#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
void k(){
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-3;i++){
		if(b[i+1]<=m&&b[i+1]+b[i+2]<=m&& b[i+1]+b[i+2]+b[i+3]>m&&b[i+1]+b[i+2]+b[i+3]<=b[i+1]+m){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--){
		k();
	} 
	return 0;
}

