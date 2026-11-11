#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int aa[500005];
int b[300005];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			aa[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int x=i;x<j;x++){
				if(aa[x]==aa[j]){
					for(int y=x;y<j;y++){
						aa[y]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(aa[j]!=0) b[aa[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	
	return 0;
	
}
