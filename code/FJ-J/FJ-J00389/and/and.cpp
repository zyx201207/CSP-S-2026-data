#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
long long z,num;
string x,y;
void dfs(){
	int c,d,p,q;
	c=1;
	p=b[1];
	while(p>0){
			y[c]=p%2+'0';
			c++;
			p=p/2;
		}
	for(int i=2;i<=m;i++){
		d=1;
		p=b[i];
		while(p>0){
			x[d]=p%2+'0';
			d++;
			p=p/2;
		}
		z=0;
		if(c>d){
			p=c;
			c=d;
		}
		else{
			p=d;
		}
		
		for(int i=c;i<p;i++){
			y[i]='0';
		}
		c--;
		p--;
		for(int j=c;j>=1;j--){
			if(x[j]!=y[j]){
				y[j]='0';
				z=z*2;
			}
			else{
				y[j]='1';
				z=z*2+1;
			}
		}
	}
	
	cout<<z<<endl;
	if(num<z){
		num=z;
	}
	return;
}
void hs(int k,int e){
	if(k==m+1){
		dfs();
		return ;
	}
	for(int i=e;i<=n;i++){
		b[k]=a[i];
		hs(k+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	hs(1,1);
	cout<<num;
	return 0;
} 
