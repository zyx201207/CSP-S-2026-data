#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int desk[1000000];
int cnt[1000000];
void clean(int j){
	for(int i=j+1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(a[k]==desk[i]){
				a[k]=0;
				n--;
			}
		}
	desk[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		desk[i]=0;
		}
		int p=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=p;k++){
				if(desk[k]==a[j]){
					clean(j);
					p=1;
					
				}

			}
			desk[p]=a[j];
			p++;
			
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=p;k++){
				if(desk[k]==j){
					cnt[j]++;
					break;
				}
			}
		}	
	}	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
}
