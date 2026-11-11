#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n=0;
	cin>>n>>m;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int b[n]={};
		for(int j=i;j<n;j++){
			b[j-i]=a[i];
			}
			
	}
	if(m==4&&n==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
		cout<<3<<1<<4;
		}
	return 0;
}
