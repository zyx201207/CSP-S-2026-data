#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int c[n];
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	int sum,num;
	for(int i=n;i>=1;i--){
		num=0;
		for(int j=i-1;j>=1;j--){
			sum=c[i];
			sum-=c[j];
			num+=sum;
			
			
		}
		if(num==m){
			ans=i;
			break;
		}
		
			
	}
	cout<<ans; 
	return 0;
}
