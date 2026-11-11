#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010];
int main(){
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdout);
	int n,m,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[500010];
	int j=1;
	for(int t=1;t<=n;t++){
		
		for(int i=t;i<=n;i++){
			int f=1;
			for(int k=1;k<=j-1;k++){
				if(b[k]==a[i]){
					j=k;
					f=0;
					break;
				}
			}
			if(f){
				b[j]=a[i];
				j++;
			}
			l=j-1;
		}
		for(int i=1;i<=l;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
