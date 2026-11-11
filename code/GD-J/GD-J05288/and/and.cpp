#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[n+1],c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		while(1){
			if(b[i]%2!=0){
				c[i]+=10;
			}
			else{
				c[i]++;
			}
			b[i]>>=1;
			if(b[i]==0){
				break;
			}
		}
	}
	int x[m+1],y[m+1];
	for(int i=1;i<=m;i++){
		x[i]=0;
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				if(c[i]>x[j]){
					for(int t=m;t>=j;t--){
						y[t]=y[t-1];
						x[t]=x[t-1];
					}
					x[j]=c[i];
					y[j]=a[i];
				}
			}
    }
    int h=y[m];
    for(int i=1;i<=m;i++){
    	h=h and y[i];
	}
	cout<<h;
	
	return 0;
} 
