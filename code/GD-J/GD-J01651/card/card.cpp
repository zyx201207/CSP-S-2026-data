#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200004],s[200004];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int d[100004],f=0;
		for(int j=i;j<n;j++){
			int w=0;
			for(int z=0;z<f&&w==0;z++){
				if(d[z]==a[j]){
					f=z;
					w=1;
				}
			}
			d[f]=a[j];
			f++;
		}
		for(int z=0;z<f;z++){
			s[d[z]]++;
		}
	}
	for(int z=1;z<=m;z++){
		cout<<s[z]<<" ";
	}
	return 0;
} 
