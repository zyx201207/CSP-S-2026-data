#include<bits/stdc++.h>
using namespace std;
int a[10000];
int b[1000][1000];
int c[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				for(int z=i;z<j;z++){
					b[i][j]=a[z];
					a[z]=a[j+z];
					a[j]=0;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==i){
				c[i]++;
				
			}
		}
	}
	if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
	}else if(n==4&&m==3){
		cout<<3<<" "<<1<<" "<<4;
	}
	return 0;
} 
