#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,len=0,flag=-1;
	cin>>n>>m;
	int t[m+1]={},cards[n]={};
	for(int i=0;i<n;i++){
		cin>>cards[i];
	}
	for(int i=0;i<n;i++){
		bool o[m+1]={0};
		int tab[n]={0};
		for (int j=i;j<n;j++){
			tab[len]=cards[j];
			len++;
			for(int k=0;k<len;k++){
				if(flag!=-1){
					tab[k]=0;
				}else if(tab[k]==cards[j]){
					flag=k+1;
				}
			}
			if(flag!=-1){
				len=flag;
				flag=-1;
			}
		}
		for(int j=0;j<len;j++){
			if (o[tab[j]]==0){
				t[tab[j]]++;
				o[tab[j]]=1;
			}
		}
		len=0;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
} 
