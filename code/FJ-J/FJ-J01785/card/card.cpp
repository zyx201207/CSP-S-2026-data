#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200000],c[100000]={0};
	int b[100000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	int i=1;
	while(i!=n+1){
		int l=0;
		for(int j=i;j<=n;j++){
			bool f=0;
			int x=0;
			for(int k=1;k<=l;k++){
				if(f){
					b[k]=0;
					continue;
				}
				if(a[j]==b[k]){
					f=1;
					b[k]=a[j];
					x=k;
				}
			}
			if(f){
				l=x;
				continue;
			}
			b[l+1]=a[j];
			l++;
		}
		bool d[100000]={0}; 
		for(int k=1;k<=l;k++){
			if(d[b[k]]==0){
				d[b[k]]==1;
				c[b[k]]++;
			}
		} 
		i++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

