#include<bits/stdc++.h>
using namespace std;
int k[500001];	int bb[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios swnc_with_stdio(false);
	cin.tie();
	int n,p;cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}int m=0,x=0,y=0;
	for(int i=0;i<n-1;i++){
		for(int j=m;j<n;j++){
			for(int r=y;r<x;r++){
				if(bb[x]==bb[r])x=r;
			}
			bb[x]=k[j];
		}m++;y=x;
	}m=0;
	for(int j=0;j<p;j++){
		for(int i=0;i<x;i++){
		bb[i]==i;m++;
	}
	}cout<<m<<" ";
	
	}
