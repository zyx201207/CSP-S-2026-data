#include<bits/stdc++.h>
using namespace std;
long long a[10000001],b[10000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=m;z++){
		int num=0;
		for(int i=1;i<=m;i++){
	
			for(int j=1;j<=n;j++){
				if(a[z]+i==a[j]){
					num++;
				}
			}
			
		}
		b[z]=num+1;
	}
	for(int i=1;i<=m*m;i++){
		for(int j=i;j<=m*m;j++){
			if(b[i]<b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	cout<<b[1];
	return 0;
} 
