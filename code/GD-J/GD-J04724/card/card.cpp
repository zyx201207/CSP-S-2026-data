#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	vector<int> v(n),cnt(m,0),table;
	for(int &a:v){
		cin>>a;
	}
	for(int j=0;j<n;j++){
		for(int i=j ;i<n;i++){
			auto put=find(table.begin(),table.end(),v.at(i));
			if(put!=table.end()){
				table.erase(put,table.end());
			}
			table.push_back(v.at(i));
		}
		for(int i=0;i<static_cast<int>(table.size());i++){
			vector<bool> flag(m,false);
			if(!flag.at(table.at(i)-1)){
				cnt.at(table.at(i)-1)++;
				flag.at(table.at(i)-1)=true;
			}
		}
		table.clear();
	}
	for(int a:cnt){
		cout<<a<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
