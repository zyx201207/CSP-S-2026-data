#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100000];
	int maxn=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	char save[10000];
	for(int i=0;i<n;i++){
		char c[100000];
		int j=0;
		while(a[i]>0){
			char b=a[i]%2+48;
			a[i]/=2;
			c[j]=b;
			j++;
		}
		int z=1;
		for(int k=j-1;k>=0;k--){
			for(int)
			save[z]+=c[k];
			z++;
		}
	}
	
	for(int i=0;1<n;i++){
		for(int j=0;j<n;j++){
			if(a[i] and a[j]>maxn){
				maxn=a[i] and a[j];
			}
		}
		
	}
	cout<<maxn;
	return 0;
} 
