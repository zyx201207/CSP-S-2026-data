#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005];
int main(){
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	int n,m,p=0;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		for(int j=1+p;j<=n;j++){
			int t=a[j];
 			if(b[t]==0) b[t]=j;
 			else if(b[t]!=0){
 				for(int z=b[t];z<j;z++){
 					b[a[z]]=0;
		 		}
		 		b[t]=j;
		 	}
	 	}
	 	for(int j=1;j<=m;j++){
	 		if(b[j]!=0) c[j]+=1;
		}
		p+=1;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
