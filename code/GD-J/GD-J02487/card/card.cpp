#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={},zhuo[n]={},num[m]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		    zhuo[j]=0;
	    }
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				if(zhuo[k]==a[j]){
					for(int l=k;l<n;l++){
						zhuo[l]=0;
					}
			        break;
				}
			}
			zhuo[j]=a[j];
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<n;k++){
				if(zhuo[k]==j){
					num[j-1]++;
					break;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<num[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}
