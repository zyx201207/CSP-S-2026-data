#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[500010],ans[500010],p=1,o=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		if(i==1){
			t[p++]=a[i];
		}
		else {
			for(int j=1;j<=p;j++){
				if(t[j]==a[i]){
					for(int k=j;k<=p;k++){
						t[k]=0;
						p--;
					}
				}
			}
			t[p++]=a[i];
		}
		for(int j=1;j<=p;j++){
			
		}
	}
	//:(
	return 0;
} 
