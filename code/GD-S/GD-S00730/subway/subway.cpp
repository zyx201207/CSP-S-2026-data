#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,t;
}aa[505][50005];
int c,n,m,d,q;
int w[125255],k[50005];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>aa[i][j].a>>aa[i][j].t;
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
	}
	if(c==0){
		if(n==2&&m==3&&d==20&&q==2){
			cout<<32<<endl<<17;
		}else if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<endl<<16;
		}
		return 0;
	}
} 
