#include<bits/stdc++.h>
using namespace std; 
int a[200005],s[30],two[200005][30];
long long ans=0; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int u=536870912,k=0,p=n-m;
	while(u!=0){
		k++;
		int c[200005]={ },sum=0;
		for(int i=1;i<=n;i++){
			if(u<=a[i]){
				a[i]-=u;
				s[k]++;
				two[i][k]=1;
			}
			else if(two[i][k]==1){
				s[k]++;
			}
			else{
				sum++;
				c[sum]=i;
			} 
		}
		if(p>=(n-s[k])){
			for(int i=1;i<=sum;i++){
				p--;
				for(int j=1;j<=30;j++){
					two[c[i]][j]=1;
				}
			}
			ans+=u;
		}
		u/=2;
	}
	cout<<ans;
	return 0;
}
