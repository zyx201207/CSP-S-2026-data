#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int x=0;
		for(int j=0;j<n;j++){
			if(a[j]==i) x=j;
		}
		x+=1;
		for(int j=x-1;j>=0;j--){
			for(int k=x+1;k<n;k++){
				if(a[j]==a[k]){
					x-=1;
				}
			}
		}
		cout<<x<<" ";
	}
	return 0;
}

