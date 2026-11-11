#include <bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("card.in");
ofstream fout("card.out");
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int b[n][m+1]={},l[n]={};
	int w[m]={};
	
	w[a[n-1]]=n-1;
	l[n-1]=1;b[n-1][0]=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(w[a[i]]==0){
			w[a[i]]=i;
			l[i]=l[i+1]+1;
			for(int j=0;j<l[i+1];j++){
				b[i][j]=b[i+1][j]; 
			}
			b[i][l[i]-1]=a[i];
		}
		else{
			if(w[a[i]]==n-1){
				l[i]=1;
				b[i][0]=a[i];
				continue;
			}
			int p=w[a[i]];
			l[i]=l[p+1]+1;
			for(int j=0;j<l[p+1];j++){
				b[i][j]=b[p+1][j]; 
			}
			b[i][l[i]-1]=a[p];
		}
	}
	int ans[m+1]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<l[i];j++){
			ans[b[i][j]]++;
		//	cout<<b[i][j]<<" ";
		}
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
