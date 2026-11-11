#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r","std.in");
	freopen("card.out","w","std.out");
	int n=0,m=0;
	cin>>n>>m;
	int a[n]={0},p[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[m+1]={0};
	for(int i=0;i<n;i++){	 
		int p[n]={0};
		for(int j=i;j<n;j++){
			p[j]=a[j];
			for(int k=0;k<n;k++){
				if(p[k]==p[j]){
					for(int s=k;s<j;s++){
						p[s]=0;
					}
				}
			}
		}
		for(int w=0;w<n;w++){
			if(p[w]==0){
				continue;
			}
			else{
				int r=p[w];
				b[r]++;
			}
		}	
	}
	for(int i=1;i<m+1;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
