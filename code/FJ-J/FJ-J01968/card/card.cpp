#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[500009]={},b[500009]={},c[500009]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=j;
			}
			else{
				for(int k=b[a[j]]+1;k<j;k++){
					b[a[k]]=0;
				}
				b[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0){
				c[i]++;
			}
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
