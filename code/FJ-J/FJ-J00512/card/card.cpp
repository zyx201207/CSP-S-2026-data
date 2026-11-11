#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[300009];
int qp[300009],h[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int l=0;
	for(int i=0,d;i<n;i++) {
		cin>>d;
		qp[l]=d;
		h[l]=i;
		int q=0;
		bool k=0;
		for(int j=0;j<l;j++){
			if(qp[j]==d){
				q=j;
				k=1;
				break;
			} 
		}
		if(k){
			for(int j=q;j<l;j++){
				b[qp[j]]+=(i-h[j]);
			}
			l=q-1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
}

