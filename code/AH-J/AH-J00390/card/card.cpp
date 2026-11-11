#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i+1]){
			for(int i=1;i<=m;i++){
				cout<<1<<" ";
			} 
		}
	}
	return 0;
}
