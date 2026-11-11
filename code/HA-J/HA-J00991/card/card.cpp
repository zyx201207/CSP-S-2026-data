#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int l=0;l<n;l++)	
		for(int i=l;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j]){
					i=j;
				}
			}
			b[k]=a[i];
			k++;
		}
	for(int j=1;j<=m;j++){int sum=0;
    	for(int i=0;i<k;i++){
    	    if(b[i]==j){
    	    	sum++;
			}
		}
		cout<<sum<<' ';
	}
	return 0;
}
