#include<bits/stdc++.h>
using namespace std;
int a[1010111],n,m,ans,maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,j=2;
	while(i<j&&j<=n){
		ans=a[i]&a[j];
		maxn=max(maxn,ans);
		j++;
		if(j>n){
			i++;j=i+1;
		}
	}
	cout<<maxn;
	return 0;
} 
