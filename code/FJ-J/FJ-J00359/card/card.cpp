#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1]={0},b[m+1]={0},d[n+1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int s1=0;
		for(int j=i;j<n;j++){
			int s=0,k;
			for(k=i;k<j;k++){
				if(d[k]==a[j]){
					s=1;
				}
				if(s){
					d[k]=0;
				}
			}
			for(k=0;k<j;k++){
				if(d[k]==0){
					break;
				}
				else{
					s1+=1;
				}
			}
			d[s1]=a[j];
		}
		for(int j=i;j<n;j++){
			if(d[j]!=0){
				b[d[j]]+=1;
				d[j]=0;
			}
		}
		a[i]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}