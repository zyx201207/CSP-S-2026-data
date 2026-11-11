#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100000],b[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i-1;j<n;j++){
			b[i]==a[j];
			for(int f=0;f<j;f++){
				if(b[i]==b[f]){
					b[i]&&b[f]==0;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]==0){
			continue;
		} 
		else{
			cout<<b[i];
		}
	}
	return 0;
} 
