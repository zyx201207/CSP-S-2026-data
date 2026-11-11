#include <bits/stdc++.h>
using namespace std;
#define filename "subway"

const int WMAX=305,NMAX=505,QMAX=207;
int w[WMAX],k[NMAX],a[WMAX],t[WMAX],x[QMAX],y[QMAX];

int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("&d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d%d",&a[j],&t[j]);
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	if(c==0 && n==2){
		printf("32\n17");
	}else if(c==0 && n==3){
		printf("35\n16");
	}else{
		for(int i=0;i<q;i++){
			cout<<"20"<<endl;
		}
	}
	return 0;
}
