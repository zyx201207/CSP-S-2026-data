#include<bits/stdc++.h>
using namespace std;
vector<int> card;
vector<int>table;
int f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin >> n >> m; 
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		card.push_back(a);
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<card.size();j++){
			if(table.size()==0){
				table.push_back(card[j]);
			}else{
				bool p=false;
				for(int k=0;k<table.size();k++){
					if(table[k]==card[j]){
						table.erase(table.begin()+k,table.end());
						table.push_back(card[j]);
						p=true;
					}
				}
				if(!p){
					table.push_back(card[j]);
				}
			}
		}
		for(int k=0;k<table.size();k++){
			f[table[k]]++;
		}
		table.erase(table.begin(),table.end());
	}
	for(int i=1;i<=m;i++){
		cout << f[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
