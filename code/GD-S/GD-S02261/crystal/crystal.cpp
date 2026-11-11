#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	int n,m,k=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[j]=a[j];
		}
		int o=0,p=i;
		while(o<m && b[n-1]!=b[i]){
			if(b[p]==b[i]){
				p++;
			}
			else if(b[p]<b[i]){
				b[p]+=1;
				o++;
			}
		}
		int g=0;
		for(int j=0;j<n;j++){
			if(b[j]==b[i]){
				g++;
			}
		}
		if(g>k){
			k=g;
		}
	}
	cout<<k;
	return 0;
} 
