#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int x=1;x<=t;x++){
		cin>>n>>d;
		int a[2000001],p=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]<=2*d&&a[i+3]-a[i]>d){
				p++;
			}
		}
		cout<<p<<endl;
	}
	return 0;
}
