#include<bits/stdc++.h>
using namespace std;
struct card{
	int ju;
	int pai[10000001];
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	card p[10000001];
	for(int i=0;i<n;i++){
		p[i].ju=i+1;
		for(int j=i;j<n;j++){
			p[i].pai[j]=a[j];
			for(int k=i;k<j;k++){
				if(p[i].pai[j]==p[i].pai[k]){
					for(int l=k;l<j;l++){
						p[i].pai[l]=0;
					}
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(p[j].pai[k]==i+1){
					sum++;
				}
			}
		}
		cout<<sum<<" ";
	}
	return 0;
} 
