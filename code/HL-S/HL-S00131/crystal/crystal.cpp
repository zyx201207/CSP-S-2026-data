#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,i,j,h,ans,s=0,t=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			for(h=n;h>=1;h--){
				if(a[i]+j==a[h]){
					s++;
				}
				t=max(s,t)/2;
			}
		}
	}
	cout<<t;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
