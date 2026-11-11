#include<bits/stdc++.h>
using namespace std;
int n,m,a,sum;
vector<int>includ[35]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=0;j<=30;j++){
			if(a/(1<<j)==1){
				includ[i].push_back(a);
				//cout<<(1<<j)<<" ";
			}
		}
	}
	int idx=30;
	vector<int>inc[35];
	while(idx>=0){
		while(idx>1&&includ[idx].size()<m)idx--;
		for(int i=0;i<=idx;i++){
			inc[i].erase(inc[i].begin(),inc[i].end());
			if(includ[idx][i]/(1<<i)==1){
				inc[i].push_back(includ[idx][i]);
			}
		}
		sum+=1<<idx;
		idx--;
		cout<<sum<<" ";
		for(int i=0;i<=idx;i++){
			includ[i].erase(includ[i].begin(),includ[i].end());
			for(int j=0;j<inc[j].size();j++){
				includ[i].push_back(inc[i][j]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}

