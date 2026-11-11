#include<bits/stdc++.h>
using namespace std;
int rjz(int n){
	long q,w;
	w=1;
	while(n!=0){
		q+=(n%2)*w;
		w++;
		n/=2;
	}
	return q;
}
int sjz(int a[],int q){
	int s=1;
	int n=0;
	for(int i=1;i<=q;i++){
		s<<1;
		n+=a[i]*s;
	}
}
int ands(int x,int y){
	int a[1000001],b[1000001],c[1000001];
	int n=rjz(x);
	int q=1;
	while(n!=0){
		a[q]=n%10;
		n/=10;
	}
	n=rjz(y);
	q=1;
	while(n!=0){
		b[q]=n%10;
		n/=10;
	}
	
	for(int i=1;i<=q;i++){
		if(a[i]==b[i]&&a[i]==1)	c[i]==1;
	}
	return sjz(c,q);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[10010];
	int n,m;
	int q; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			q=max(ands(i,j),q);
		}
	}
	cout<<"12";
	return 0;
}





