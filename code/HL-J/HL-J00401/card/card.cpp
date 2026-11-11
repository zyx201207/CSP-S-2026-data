#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,i,j,p,q;
	int c[n]={};
	int a[n]={};
	int b[m+1]={};
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[j];
		}
		cout<<endl;
		for(j=i;j<n;j++){
			c[j]=a[j];
		}
		for(j=i;j<n;j++){
			for(p=i;p<j;p++){
				if(c[j]==c[p]){
					for(q=p;q<j;q++){
						c[q]=0;
					}
				}
			}
		}	
		for(p=i;p<n;p++){
			b[c[p]]++;
		}
	} 
	for(i=1;i<m+1;i++){
		cout<<b[i]<<' ';
	}
	
	return 0;
} 
