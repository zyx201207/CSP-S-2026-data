#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int N[100005]={};
	short check[100005]={};
	int zhan[100005]={};int s=0;//sai dao na
	int ans[100005]={};
	int topa=-1;//zhan tou
	int n,m;
	cin >>n>>m;
	
	//queue <int> card;
	for (int i=0;i<n;i++){
		cin >>N[i];
	}
	for (int i=0;i<n;i++){
		s=0;
		for (int j=i;j<n;j++){
			if (check[N[j]]=0){
				zhan[s]=N[j];
				check[N[j]]=1;
				s++;
				topa++;				
			}else{
				while (zhan[topa]!=N[j]){
					check[zhan[topa]]=0;
					zhan[topa]=0;
					topa--;
					s--;
					
				}
				zhan[topa]=0;
				s--;
				topa--;
				zhan[s]=N[j];
				s++;
				topa++;
				
			}
			//zhan[s]=N[j];
			//check[N[j]]=1;
			//s++;
		}
		for (int o=0;zhan[o]!=0;o++){
			ans[zhan[o]]++;
			zhan[o]=0;
		}
		for (int o=0;o<100006;o++){
			check[o]=0;
		}
		topa=-1;
		
			
	}
	for (int i=0;i<100006;i++){
		if (ans[i]!=0){
			cout <<ans[i];
		}
	}
	
	
	
	
	return 0;
}
