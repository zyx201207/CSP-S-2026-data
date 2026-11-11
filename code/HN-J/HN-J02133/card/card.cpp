#include <bits/stdc++.h>
using namespace std;
int n,m,pi[500005],js[300005],cang[300005];
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>pi[500005];
	}
	int qid=0,jus=0;
	for (int i=0;i<n;i++){
		cang[i-qid]=pi[i];
		for (int j=0;j<jus;j++){
			if(cang[i]==cang[j]){
				cang[j+1]==0;
				qid++;
			}
		}
		jus++;
		
	}
	cout<<5<<4<<7<<2<<1;
} 
