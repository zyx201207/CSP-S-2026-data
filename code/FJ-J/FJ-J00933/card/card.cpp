#include<bits/stdc++.h>
using namespace std;
int a[510000],t[510000],ans[510000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	int s=a[1];	 
	for(int i=1;i<=n;i++){	
		if(a[i+1]==a[i-1]){
			ans[i]=t[a[i]];
		}else{
			ans[i]=n;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
