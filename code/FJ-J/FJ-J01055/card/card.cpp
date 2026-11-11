#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[300005]={};
int findx(int x,int id){
	for(int i=id+1;i<n;i++){
		if(a[i]==x)  return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=true;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;){
			int pos=findx(a[j],j);
			if(pos!=-1){
				b[j]=false;
				j=pos;
				b[j-1]=false;
			}
			else{
				j++;
			}
		}
		int d=0;
		for(int j=i;j<n;j++){
			if(!b[j]){
				if(d==0)  d=1;
				else  d=0;
			}
			else{
				if(d==0){
					sum[a[j]]++;
				}
			}
			b[j]=true;
		}
	}
	for(int i=1;i<=m;i++)  cout<<sum[i]<<' ';
	return 0;
}
