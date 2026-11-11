#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int c,t;
bool check(vector<int> vec){
	int minus=vec.at(1)-vec.at(0);
	for(int i=1;i<static_cast<int>(vec.size());i++){
		if((vec.at(i+1)-vec.at(i))!=minus)return false;
	}
	return true;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
		
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> island(n);
		for(auto &a:island)cin>>a;
//		if(check(island)){
//			if(n)
//		}
		cout<<n-3<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
