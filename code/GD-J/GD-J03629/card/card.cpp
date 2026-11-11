#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n[10000];
int ans[10000];
bool yn[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}		
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;i++){
			n[num++]=a[j];
		}
		for(int j=0;j<num;j++){
			if(y[a[j]]==1){
				for(int k=1;k<=1000;k++){
					if(n[k]==a[j]){
						ans++;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
