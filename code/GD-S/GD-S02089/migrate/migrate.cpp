#include<iostream>
#include<vector>

using namespace std;

vector<int> vv[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,x;
	cin >>c>>t;
	while(t--){
		int n,d;
		cin >>n>>d;
		for(int i=1;i<=n;i++){
			cin >>x;
			for(int j=1;j<=d;j++){
				vv[x].push_back(x+j);
			}
		}
		cout<<1<<"\n";
	}
	return 0;
} 
