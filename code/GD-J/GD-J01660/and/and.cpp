#include<bits/stdc++.h>
using namespace std;
int a[100005];
int cc[25][100005];
int ans[25];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;					//DOGGOD_QÀ„∑®£®£ø£© 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1)cout<<a[n];
	for(int i=1;i<n;i++){
	for(int j=0;j<=21;j++){
		if(a[i]>=pow(2,j)){
			cc[i][j]=1;
			a[i]-=pow(2,j);
			maxn=j;
		}
	
	}	
	}
	for(int i=0;i<=20;i++){
		ans[i]=cc[n][i];
	}
	 for(int i=maxn;i>=0;i--){
	 	for(int j=1;j<=n;j++){
	 		if(cc[j][i]==1){
	 			for(int k=0;k<=i;k++){
	 				ans[k]^=cc[j][i];
	 			
				 }
			 }
		 }
	 }
	
	int answerrr=0;
	for(int i=0;i<=20;i++){
		answerrr+=ans[i]*pow(2,n);
	}
	cout<<answerrr;
}
