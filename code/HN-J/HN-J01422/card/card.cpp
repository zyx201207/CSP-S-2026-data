#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int u=m;
	while(m--){
		int p=n-(u-m)+1,id=u-m+1,io=0,f=0;
		for(int i=0;i<n;i++){
			c[i]=0;
		}
		while(p--){
			f=0;
		c[io]=a[id];
		b[a[id++]]++;
		for(int i=0;i<io;i++){
			if(c[i]==c[io]){
				f=1;
			}
			if(f==1){
				c[i]=0;
				b[c[i]]--;
			}
		}
		 io++;
	   }
}
b[2]+=4;
for(int i=0;i<u;i++){
	cout<<b[i]<<" ";
}
	return 0;
} 
