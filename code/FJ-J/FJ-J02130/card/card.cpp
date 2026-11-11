#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010]={-1},b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int p=i+1;p<=j;p++)if(a[p]==a[j])for(int k=j;k<=p;k++)a[k]==-1;
		}
		for(int j=i;j<=n;j++)if(a[j]!=-1)b[a[j]]++;
	}
	for(int i=1;i<=300010;i++){
		if(b[i])cout<<b[i]<<" ";	
	}
	return 0;
}
