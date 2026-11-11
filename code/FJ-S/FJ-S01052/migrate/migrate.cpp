#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		long long n,m,a[10001],s=0;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}for(long long i=1;i<=n-3;i++){
			if(a[i+3]-a[i]==2*m-1 && a[i+1]-a[i]<=m &&a[i+2]-a[i]<=m){
				s++;
			}
		}
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
