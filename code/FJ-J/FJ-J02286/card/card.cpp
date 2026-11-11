#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,round[5000][2],card[500000],table[5000],location;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=m;i++){
		round[i][0]=i;
	}
	for(int i=0;i<n;i++){
		location=i;
		for(int j=i;j<n;j++){
			table[j]=card[j];
			for(int y=location;y<i+j;y++){
				if(table[j]==table[y]){
					location=j;
					break;
				}
			}
		}
		for(int x=1;x<=m;x++){
			for(int z=location;z<n;z++){
				if(table[z]==table[x]){
				round[x][1]++;
				break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<round[i][1]<<" ";
	}
	return 0;
} 
