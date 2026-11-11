#include<bits/stdc++.h>
using namespace std;
long long INF=pow(10,6);
int is[100000];
int n,d;
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>is[j];
		}
		int count=0;
		for(int p=0;p<n;p++){
			vector<vector<int>> nis;
			vector<int> w={p};
			nis.push_back(w);
			int least[n];
			int ru[n];
			for(int j=0;j<n;j++){
				least[j]=INF;
				ru[j]=0;
			}
			while(not nis.empty()){
				vector<int>road;
				road=nis[0];
				nis.erase(nis.begin());
				int r,l;
				r=road[road.size()-1];
				if(road.size()+1<=least[r]){
					least[r]=road.size()+1;
					ru[r]++;
				}
				if(r+1>=n){
					continue;
				}
				for(int y=r+1;y<n;y++){
					if(is[y]-is[r]<=d){
						vector<int> road1=road;
						road1.push_back(y);
						nis.push_back(road1);
					}
				}
			}
			for(int j=0;j<n;j++){
				if(ru[j]==2){
					count++;
				}
			}
		}
		
		cout<<count<<'\n';
	}
	
}
