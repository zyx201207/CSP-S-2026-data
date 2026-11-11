#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,c,t,m,u,v,l;
	cin>>c>>t>>n>>d;
	int sum=0;
	int x[100005];
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			while(l>=1&&l<=m-1){
			if(x[i]-x[j]>d){
				break;
			}else if((x[i]-x[j]<=d||x[i]-x[j+1]<=d||x[i]-x[j+3]<=d)||x[i]-x[n]<=d){
				sum++;
			}
	      }
		}
	}
	cout<<sum;
	return 0;
} 
