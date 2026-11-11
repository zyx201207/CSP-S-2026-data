//GZ-J00450 —Ó”¿ÚØ ∫Î“„÷–—ß 
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin.tie(0);
	cin>>n>>m;
	int r;
    for(int i=1;i<=m;i++){
    	a[i]=i;
	}
	for(int i=0;i<n;i++){
		cin>>r;
		int j=m;
		while(j>0&&a[j]!=r){
			
			a[j]=0;j--;
		}
		if(a[j]==r){
			m=j;
		}
		if(j==1&&a[j]!=r){
			m=m+1;
			a[m]=r;
		}
	}
	for(int i=0;i<m;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
		if(a[i]==0){
			break;
		}
	}

	return 0;
} 
