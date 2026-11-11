#include<bits/stdc++.h>
using namespace std;
int paidui[500001];
int answer[300001];
int main(){
	int n,m;cin>>n>>m;
	int x=1;
	int card[n];
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int j=1;j<=n;j++){
		paidui[j]=card[j+1];
		if(paidui[j]==card[j]){
			for(int k=1;k<=sizeof(paidui);k++){
				paidui[k]=0;
			}
		}
		else{
			paidui[j+1]=card[j];
		}
		for(int l=1;l<=sizeof(paidui);l++){
			if(paidui[l]==x) answer[l]++;
			
		}
	}
	for(int o=1;o<=m;o++){
		cout<<answer[o];
	}
	return 0;
} 
