#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
int ans[300007]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool cmp[300007]={};
		for(int j=i;j<n;j++){
			if(!cmp[a[j]]) ans[a[j]]++;
			cmp[a[j]]=1;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	
	return 0;
}
