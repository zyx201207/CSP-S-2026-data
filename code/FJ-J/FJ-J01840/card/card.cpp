#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],ji[m+1]={0},t[n],d[n]={0},x;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(d[a[j]]==0) d[a[j]]++;
			else{
				d[t[j]]=1;
				for(int z=i;z<n;z++){
					if(a[z]==a[j]) x=z;
				}
				for(int z=x;z<j;z++){
					d[t[z]]=0;
					t[z]=0; 
				}
			}
		}
		for(int j=i;j<n;j++){
			if(d[j]!=0) ji[t[j]]++;
		}
		for(int j=0;j<n;j++){
			t[j]=a[i];
			d[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ji[i]<<' ';
	}
	return 0;
}
