#include<bits/stdc++.h>
using namespace std;
int m,n; 
int a[500010];
int b[500010];
int c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(b[j]==b[k] && b[j]!=0){
					for(int l=j;l<k;l++) b[l]=0;
				}
			}
		}
		for(int j=i;j<n;j++){
			for(int k=1;k<=m;k++){
				if(b[j]==k) c[k]+=1;
			}
		}
		for(int j=i;j<n;j++){
			b[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

