#include<bits/stdc++.h>
using namespace std;
int n,m,b,c,d,f,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+10],e[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
		e[i]=0;
	}
	for(int i=0;i<n;i++){
		b=a[i]; 
		d=0;
		for(int j=0;j<i;j++){
			c=a[j];
			while(b>c&&d<m){
				c++;
				d++;
			}
			if(b==c){
			f++;
			}
		}
		e[i]=f;
	}
	for(int i=0;i<n;i++){
		if(e[i]>x){
			x=e[i];
		}
	}
	cout<<x;
	return 0;
}	

