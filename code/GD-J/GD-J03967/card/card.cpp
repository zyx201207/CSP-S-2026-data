#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={0},count[m+1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int sum=0,x[n]={0};
		for(int j=i;j<n;j++){
			bool p=false;
			int sumi=0;
			for(int l=0;l<sum;l++){
				if(p){
					x[l]=0;
				}else if(a[j]==x[l]){
					p=true;
					sumi=l;
				}
			}
			if(!p){
				x[sum]=a[j];
				sum++;
			}else{
				sum=sumi;
				x[sum]=a[j];
				sum++;
			}
		}
		for(int j=0;j<sum;j++){
			int h=x[j];
			count[h]+=1;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<count[i]<<" ";
	}
	return 0;
}
