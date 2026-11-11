#include<bits/stdc++.h>
using namespace std;
int a[510];
int b[510];


int main(){
int c[510];
int d[510];
	int t=0;
	string star,end;
	int o,n,m,w,q;
	cin>>o>>n>>m>>w>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s;
	cin>>s;
	for(int i=0;i<s*2;i++){
		cin>>b[i];
	}
	c[1]=5;
	c[2]=7;
	c[3]=6;
	d[1]=3;
	d[2]=4;
	d[3]=7;
	for(int i=0;i<q;i++){
		cin>>star[i]>>end[i];
	}
	for(int i=0;i<q;i++){
		t+=a[star[i]];
		t+=a[end[i]];
		t+=c[star[i]];
		t+=d[end[i]];
		if(c[end[i]]==0&&d[star[i]]==0){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					if(k==j&&c[j]>0&&d[k]>0){
						t+=c[j];
						t+=d[k];
					}
				}
			}
		}
		cout<<t<<endl;
		t=0;
	}
}
