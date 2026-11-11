#include<bits/stdc++.h>
using namespace std;
int n,m,a[300150],b[300150],c[300150],card[500150];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int h;
		cin>>h;
		card[i]=h;
		a[h]++;
	}
	for(int k=0;k<n;k++){
		memset(b,0,sizeof b);
		int f=0;
		for(int i=k;i<n;i++){
			b[card[i]]++;
			if(f){
				if(card[i]==f){
					
					if((a[card[i]]-b[card[i]])<1){
						//cout<<'g'<<i;
						f=0;	
					}
				}
				continue;
			}
			if(a[card[i]]-b[card[i]]>0){
				f=card[i];
				c[card[i]]++;
				//cout<<'f'<<i;
				continue;
			}
			else{
				c[card[i]]++;
				//cout<<i;
			}
		} 
		a[card[k]]--;
		/*
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
		cout<<endl;*/
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
} 
