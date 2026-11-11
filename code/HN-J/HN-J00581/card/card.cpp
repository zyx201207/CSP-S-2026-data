#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[M],f1=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			f1=0;
		}
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int k=j+1;
				while(a[j]!=a[k]&&k<=n){
					k++;
				}
				if(k>n){
					b[a[j]]++;
				}
				else{
					j=k-1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	else if(f1==1){
		for(int i=n-1;i>=1;i--){
			if(a[i]==a[i+1]){
				b[a[i]]=i+1;
				break;
			}
			else{
				b[a[i+1]]=i+1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	return 0;
} 
