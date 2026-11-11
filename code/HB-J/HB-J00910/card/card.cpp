#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],c[200005],op;
void cht(int c,int u){
	for(int i=1;i<=c;i++){
		if(b[i]==u){op=i;break;}
			
	}
}
void cc(){
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			c[b[i]]++;
		}
	}
}
void gg(){
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
}
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
	for(int i=2;i<=n;i++){
		cht(i,b[i]);
		if(op){
			int p=op;
			for(int k=p;k<i;k++) b[k]=0;
		}
	}
	gg();
	cc();
	}
	for(int i=1;i<=m;i++){cout<<c[i]<<" ";}
	return 0;
}
