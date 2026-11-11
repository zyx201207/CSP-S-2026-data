#include<bits/stdc++.h>
using namespace std;
int a[1000005],v[1000005],b[12345];
int main(){
	freopen("i.in","r",stdin);
	freopen(".out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		int c=0,j=0;	
	while(x!=0){
		if(x%2==0){
			j++;
		}
		x=x/2;
		c++;
	}
	v[i]==j;
	j=0;
	}
	int y=0;
	int j;

		for(int i=1;i<=n;i++){
			if(a[i]=x){
				x=a[i];
			}
			}
			int i=0;
		for(int j=n;j>=1;j++){
			if(i==n-m){
				cout<<x;
               return 0;
			}
			if(x>=a[j]){
				x=a[j];
				i++;
			}
		}
	
}