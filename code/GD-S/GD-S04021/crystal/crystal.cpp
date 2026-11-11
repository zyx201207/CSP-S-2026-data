#include<bits/stdc++.h> 
using namespace std;
int n=0,m=0,cnt=0;
long long a[10^12+5]={},b[10^12+5]={},ans[10^12+5]={};
int main(){
freopen("crystal.in","w",stdin);
freopen("crystal.out","s",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n];
		ans[n]=a[n];
	}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
					if(ans[j]+k==a[k]){
						a[j]=0;
						a[k]+=1;
						ans[j]+=1;
						j=m;
					}
			}	
		}
	for(int j=1;j<=n;j++){
	for(int k=1;k<=n;k++){
		if(ans[j]!=a[k]){
			cnt=ans[j]-a[k];
		}
}
}
	cout<<cnt;
	return 0;
}
