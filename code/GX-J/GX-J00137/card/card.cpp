#include<bits/stdc++.h>
using namespace std;

int main(){
	// freopen("card1.in","r",stdin);
	// freopen("card1.out","w",stdout);
	
	// freopen("card2.in","r",stdin);
	// freopen("card2.out","w",stdout);
	
	// freopen("card3.in","r",stdin);
	// freopen("card3.out","w",stdout);
	
	// freopen("card4.in","r",stdin);
	// freopen("card4.out","w",stdout);
	
	// freopen("card5.in","r",stdin);
	// freopen("card5.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int c[n+1],num[m+1],h[n+1][n+1],ans[n+1];
	
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	
	for(int i=0;i<n;i++){
		ans[i]=i;
		for(int j=i;j<n;j++){
			for(int t=0;t<j;t++){
				if(h[i][t]==c[j]){
					ans[i]=j;
				}
			}
			h[i][j]=c[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		num[i]=0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=ans[i];j<n;j++){
			if(c[j]<=m){
				num[c[j]]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	
	return 0;
}
