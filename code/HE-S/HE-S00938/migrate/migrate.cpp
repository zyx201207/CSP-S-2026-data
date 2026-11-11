#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,p;
	cin>>c>>p;
	while(p--){
		int n,m;
		int ans=0;
		cin>>n>>m;
		int a[n+1]={};
		int b[10101]={};
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>m) b[i]=1;
		} 
		for(int i=1;i<n;i++){
			int sum=0;
			for(int j=i+1;j<=n;j++){
				if(j-i==2 && a[j]-a[i]<2*m || a[j]-a[i]==2*m-1 && b[i]==0 ){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
