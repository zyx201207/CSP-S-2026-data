#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
int n,m,num[100005],a,o[100005],start=0,copy[100005]={0},ans[100005];
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>a;
		copy[i]=a;
	}

	for(int j=0;j<n;j++){
	start=j;
	for(int i=1;i<=m;i++){
		num[i]=0;
	} 
	for(int i=j;i<n;i++){
		a=copy[i];
		if(num[a]!=1){
			num[a]=1;
		}
		else{start=i;
		}
	}
	for(int i=start;i<n;i++){
		ans[copy[i]]+=1;
	}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
return 0;}

