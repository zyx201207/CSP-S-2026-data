#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000];
map<int,int> b; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int x=n;
	while(n--){
		for(int i=1;i<=x;i++){
			for(int j=x;j>=i;j--){
				if(a[j]==a[i]){
					for(int k=j;i<=n;k++){
						b[k]++;
				break;
					}
				}
			}
		}  
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
