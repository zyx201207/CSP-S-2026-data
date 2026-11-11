#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t>0){
		t--;
		int n,d,m=0;
		cin>>n>>d;
		int x[500001];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int a[3]={};
				if(x[j]-x[i]<=d){
					a[0]=x[j]-x[i];
				}else{
					a[0]=10000;
			 }
				if(x[j-1]-x[i]<=d){
					a[1]=x[j]-x[i];
				}else{
					a[1]=9999;
				}
				if(x[j]-x[i+1]<=d){
					a[2]=x[j]-x[i];
				}else{
					a[2]=8888;
				}
				if(a[0]==a[1]&&a[1]!=a[2]||a[1]==a[2]&&a[2]!=a[0]||a[2]==a[0]&&a[0]!=a[1]){
					m++;
				}
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
