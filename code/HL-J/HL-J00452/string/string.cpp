#include <bits/stdc++.h>
using namespace std;
int n,x,y=0,z=0,d=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long b[n];
	char a[n];
	for(int i=0;i<n;i++){
		cin>>b[i]>>a[i];
	}
	for(int i=0;i<n;i++){
		x=x+b[i];
	}	
	char c[x+5];
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i];j++){
		c[y]=a[i];
		y++;
		}
	}
	y--;
	while(z<y){
		int e=int(c[z]);
		int f=int(c[y]);
		if(e!=f){
			c[y]=c[z];			
			d++;
		}
		z++;
		y--;
	}
	cout<<d;
	return 0;
}
