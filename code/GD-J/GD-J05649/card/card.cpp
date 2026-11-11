#include <bits/stdc++.h>
using namespace std;
int main(){
	int i=0,j=0,k=0,n,m,cnt=0;
	freopen("card.in","r",stdin);
	cin>>n>>m;
	int a[n],b[n],c[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	    	a[j]=0;
		}
		for(j=0;j<n;j++){
			b[j]=a[j];
			for(k=j;k>=0;k--){
				if(b[k]==b[j]&&j!=0){
					for(int x=j;x>k+1;x--){
						b[x]==0;
					}
				}
			}
		}
		for(j=0;j<n;j++){
			if(b[j]!=0){
				c[j]++;
			}
		}
		a[cnt]=0;
		cnt++;
    }
	freopen("card.out","w",stdout);
	for(i=0;i<n;i++){
		if(c[i]!=0){
			cout<<c[i]<<endl;
		}
	}
	fclose stdin;
	fclose stdout;
}







