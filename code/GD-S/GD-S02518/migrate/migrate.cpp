#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[500050],d[500050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m>>k;
	int n=0;
	for(int i=1;i<=m;i++){
		n++;
		cout<<n<<endl;
		if(n==2){
			n=0;
		} 
	}
	
	for(int i=1;i<=n;i++){
		int j=a[i]-a[i-1];
		int p=i-1;
		d[i]=j*p+k;
		k+=d[i];
	}
	return 0;
}
