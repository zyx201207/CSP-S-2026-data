#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,q=1,p=0,a[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int dp[1000][m];
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m>=q*(a[j]-a[i])&&a[j]-a[i]>=0){
				m=m-(a[j]-a[i]);
				q++;
				a[i]=a[j];
				
			}
		}
		if(q>p){
			p=q;
		}
		q=0;
	}
	cout<<p;
	return 0;
}
