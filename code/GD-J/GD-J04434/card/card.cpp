#include<bits/stdc++.h>
using namespace std;
int z[500002], y[500002], x[500002], v[500002];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>z[i];
	}
	int c=n;
	int a=0, b=0, d=0;
	while(c!=0){
		a=0;
		b=0;
		d=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<a;j++){
				if(z[i]==y[j]){
					for(int k=j;k<a;k++){
						x[b++]=y[k];
					}
					a=j;
					y[a++]=z[i];
					break;
				}
			}
		}
		for(int i=0;i<a;i++){
			v[y[i]]+=1;
		}
		for(int i=0;i<a;i++){
			x[b++]=y[i];
		}
		for(int i=0;i<b;i++){
			z[i]=x[i];
		}
	}
	for(int i=0;i<m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
