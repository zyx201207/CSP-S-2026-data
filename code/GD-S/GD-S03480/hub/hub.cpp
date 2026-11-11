#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<vector<int> > way;
void gz(vector<int> path){
	
	if (path.size()==k){
		way.push_back(path);
	}
	else{
		path.push_back(0);
		for (int i=1;i<=n;i++){
			int ok=1;
			for (int j:path){
				if (i==j)ok=0;
			}
			if (ok){
				path.pop_back();
				path.push_back(i);
				gz(path);
			}
		}
	}
} 
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for (int iop=1;iop<=t;iop++){
		scanf("%d%d",&n,&k);
		way.clear();
		gz(vector<int> {});
		
	}
	
	
	
	
}
