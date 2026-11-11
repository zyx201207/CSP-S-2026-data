#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int o=a[i];
		for(int j=0;j<i;j++){
			b[o]++;
		}
	}for(int j=0;j<n;j++){
		if(b[j]!=0){
			cout<<b[j]<<" ";
		}
	}
	return 0;
}            
