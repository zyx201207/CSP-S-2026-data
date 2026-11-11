#include<bits/stdc++.h>
using namespace std;int pd[500086];int temp[500086],tj[500086];
int find(int a,int b){
	for(int i=1;i<=b;i++){
		//cout<<temp[i]<<' '; 
		if(temp[i]==a) {return i;}
		 
	}//cout<<endl;
	return 0;
}

void erase(int a,int b){
	for(int i=a;i<b;i++){
		temp[i]=0;
	}
}


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>pd[i];
	}
	for(int i=1;i<=n;i++){
		int kj=0,xb=0;
		for(int j=i;j<=n;j++){
			int xb1=find(pd[j],kj);cout<<xb1<<' ';
			if(xb1){
				erase(xb1,kj-xb1);
				xb=kj=xb1;
			};
			temp[xb]=pd[j];
			kj++;
			xb++;
		}
		for(int j=0;j<kj;j++){
			cout<<temp[j]<<' ';
			tj[temp[j]]++;
		}
		cout<<endl;
		erase(0,n);
	}
	for(int i=1;i<=m;i++){
		
			cout<<tj[i]<<' ';
		
	}
}
