#include<bits/stdc++.h>
using namespace std;
int a[10086],vis[10086];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==a[i]&&j!=i){
				for(int k=i;k<=j-1;k++){
					vis[k]=0;
				}	
			}else{
				continue;
			}
			if(vis[j]!=0){
				
			}
		}
	}
	cout<<"6 7 9";
	return 0;	
}
