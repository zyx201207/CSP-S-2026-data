#include <bits/stdc++.h>
using namespace std;
bool inornotin(int a,int b[500000]){
	for(int i=0;i<500000;i++){
		if(a==b[i])return true;
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[500000],c[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		c[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(inornotin(a[i],b)){
				for(int i=0;i<500000;i++){
					b[i]=0;
				}
			}
			else{
				b[j]=a[j];
			}
			
		}
		for(int i=1;i<=500000;i++){
			c[b[i]]++;
		}
	}
	for(int i=0;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
