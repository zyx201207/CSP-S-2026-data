//AC-Only_Small_Number
#include<bits/stdc++.h>
using namespace std;
int n,m,r,l;
int che(int q[]){
	for(r=0;r<n-1;r++){
		for(l=r+1;l<n;l++){
			if((q[r]==q[l])&&q[r]){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],q[n],c[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		q[i]=0;
		c[i]=0;
	}
	c[n]=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			q[j]=a[j];
			int w=che(q);
			if(w){
				for(int k=r;k<l;k++){
					q[k]=0;
				}
			}
			//for(int k=0;k<n;k++)cout<<q[k]<<" ";cout<<endl;//shu1chu1
		}
		for(int j=0;j<n;j++){
			c[q[j]]++;
			q[j]=0;
		}
		//cout<<endl;
	}
	for(int i=1;i<m+1;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
