//GZ-J00355 ¶Å¾´Ðù
#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	int a[n],b[n]={0},c[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int p=0;p<n;p++){
		for(int i=p;i<n;i++){
			k++;
			for(int j=i;j>=0;j--){
				if(a[i]==b[j]){
					for(int f=j;f<=i;f++){
						b[f]=0;
						k--;
					}
					break;
				}
			}
			b[k]=a[i];
		}for(int i=0;i<n;i++){
			if(b[i]!=0){
			}
		}
	}
	for(int i=0;i<n;i++){
		if(c[i]!=0){
			cout<<c[i]<<' ';
		}
	}
}
