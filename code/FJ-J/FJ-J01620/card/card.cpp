#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],r=1;
int f[5000005];
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=r;k++){
				if(f[k]==a[j]){
					r=k-1;
					break;
				}
			}
			r++;
			f[r]=a[j];
		}
		for(int j=1;j<=r;j++){
			//cout<<f[j]<<" ";
			b[f[j]]+=1;
		}
		//cout<<r<<"\n";
	} 
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

