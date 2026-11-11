#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> map;
int res=2000050;
int ans;
int BFS(long long x,long long y){
	queue<int> q;
	int cnt=0;
	for(int i=x+1;i<=y;i++){
		if(map[x][i]==1){
			q.push(i);
		}else{
			break;
		}
	}
	BFS(q.top(),y);
	cnt++;
	q.pop();
	if(x==y){
		res=min(res,cnt);
		ans=1;
	}
	if(res==cnt){
		ans++;
	}
	return ans;
}
int main(){
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	int c,t;
	//cin>>c>>t;
	fin>>c>>t;
	for(int k=0;k<t;k++){
		int num;
		int answer=0;
		long long d;
		//cin>>num>>d;
		fin>>num>>d;
		long long arr[num];
		for(int i=0;i<num;i++){
			//cin>>arr[i];
			fin>>arr[i];
		}
		for(int i=0;i<num;i++){
			for(int j=i+1;j<num;j++){
				if(arr[i]+d>=arr[j]){
					map[i][j]=1;
				}
			}
		}
		for(int i=0;i<num;i++){
			for(int j=i+1;j<num;j++){
				if(BFS(i,j)==2){
					answer++;
				}
			}
		}
		//cout<<answer<<"\n";
		fout<<answer<<"\n";
	}
	return 0;
}
