#include<bits/stdc++.h> 
using namespace std;
int n,m,now,timen,zhao,linshi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	now=n;
	int tablen[m]={0};
	int table[n]={0};
	int hand[n]={0};
	int still[m]={0};
	for(int i=0;i<n;i++)
		cin>>hand[i];
	while(n--){
		now=n+1;
		timen=0;
		while(now){
			table[timen]=hand[timen];
			linshi=hand[timen];
			tablen[linshi]++;
			for(int i=0;i<m;i++){
			
				if(tablen[i]>1){
					zhao=i;
					for(int j=0;j<n;j++)
					{
						if(table[j]==zhao){
							for(int h=j;h<=n;h++) table[h]=0;
						}
					}
					tablen[i]=1;
				}
			}
			now--;
			timen++;
		}
		for(int i=0;i<m;i++) still[i]=tablen[i];
	}
	for(int i=0;i<m;i++){
		cout<<still[i];
	}
	
	
	
	
	
	
	return 0;
	}
