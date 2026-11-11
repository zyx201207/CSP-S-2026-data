#include<bits/stdc++.h>
using namespace std;
int a[200008],ans[200008];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j||)break;
			ans[i]=a[i]&a[j];
		}
	}
	cout<<max(ans+1,ans+n+1);
	
	return 0;
}
