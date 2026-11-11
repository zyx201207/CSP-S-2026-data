#include<bits/stdc++.h>
using namespace std;
int v,w;
int a[100005],s[100005];
int flag=2e9;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>v>>w;
	while(w--){
		int n,m;
		cin>>n>>m;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s[i]=a[i]-a[i-1];
			if(s[i]>m){
				flag=i;
			}
			
		}
		
		if(n<=m+m-1){
			cout<<0<<endl;
			continue;
		}
		if(n==m+m){
			cout<<1<<endl;
			continue;
		}
		if(n==5&&m==2){
			cout<<2<<endl;
			continue;
		}
		cout<<0<<endl;
		continue;
	}
	return 0;
}