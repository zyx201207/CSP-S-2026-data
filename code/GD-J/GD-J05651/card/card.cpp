#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],t[500002],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(1){
			ans[a[j]]++;
			j=t[a[j]]+1;
			if(j>n)break;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0; 
}
