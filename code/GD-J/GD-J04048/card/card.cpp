#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int zm[100000];
	int dc[100000];
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			dc[j]=a[i];
			cout<<dc[i];
		}
	}
	return 0;
}
