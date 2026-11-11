#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	int n,m;
	cin>>n>>m;
	int a[n],ot[m],t[n],p=0;
	for(int i=0;i<n;i++)	cin>>a[n];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int k=0;
			for(k=0;k<p && t[k]!=a[j];k++){}
			if(k==p){
				t[p]=a[j];
				p++;
			}
			else{
				p=k+1;
			}
		}
		for(int j=0;j<p;j++){
			ot[t[j]]+=1;
		}
	}
	
	freopen("card.out","w",stdout);
	for(int i=0;i<m;i++){
		cout<<ot[i];
	}
	fclose(stdout);
}
