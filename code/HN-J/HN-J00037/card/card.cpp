#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0,y=0;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				x=i;
				y=j;
			}
		}
			for(int j=1;j<=n;j++){
				if(j>=x&&j<=y){
					
				}else{
					b[a[j]]++;
				}
			}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3
*/
